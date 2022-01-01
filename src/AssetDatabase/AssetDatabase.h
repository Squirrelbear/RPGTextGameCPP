//
// Created by Peter on 30/12/2021.
//

#ifndef RPGTEXTCPP_ASSETDATABASE_H
#define RPGTEXTCPP_ASSETDATABASE_H

#include <map>
#include "Prefab.h"
#include "../Enemies/UnitAttack.h"
#include "../Enemies/Enemy.h"
#include "../Player/Player.h"

/*
 * Stores a database of prefab information ready to create assets within the game.
 *
 * The assetDatabaseFile passed to the constructor must have each line of the file as a separate definition.
 * Each definition starts with a prefab type and then a specific ordered list of attributes required for each.
 * The following identifies the format for each of these.
 *
 * PLAYER [initial max health] [initial max mana] [attack ids (1+)]
 *      Initial max health and initial max mana should be positive integers.
 *      Attack ids should match the attack ids for attack type prefabs.
 *      Example:
 *              PLAYER 100 100 0 1 2 3 4
 *
 * ENEMYNAME [enemy type] [name]
 *      Enemy type must appear as a single word with no spaces.
 *      Name can have any amount of spacing as everything after the enemy type is considered the name.
 *      Example:
 *              ENEMYNAME Orc Thrall
 *
 * ENEMY [enemy type] [map overlay character] [initial max health] [initial max mana] [attack ids (1+)]
 *      Enemy type must appear as a single word with no spaces.
 *      Map overlay character must be a single character.
 *      Initial max health and initial max mana should be positive integers.
 *      Attack ids should match the attack ids for attack type prefabs.
 *      Example:
 *              ENEMY Orc O 100 100 5 6 7
 *
 * ATTACK [attack id] [damage min] [damage max] [critical chance] [critical damage multiplier] [mana cost] [attack name]
 *      Attack id must be a unique id for each attack.
 *      Damage min and damage max must be integer values where min is less than or equal to max.
 *      Critical chance can be a float and should be written as 60.5 for 60.5%
 *      Critical damage multiplier is a float and can be any valid float value.
 *      Mana cost must be a positive integer.
 *      Attack name can have any length with as many spaces as desired everything after mana cost is considered the name.
 *      Example:
 *              ATTACK 0 5 10 30 1.5 5 Magic Missile
 *
 * MAP [map file name]
 *      File name can be any valid file name in the application directory containing map data.
 *      Example:
 *              MAP map.txt
 */
class AssetDatabase {
public:
    // Initialises the database by loading all contents of the assetDatabaseFile.
    explicit AssetDatabase(const std::string& assetDatabaseFile);

    /*
     * Checks for a valid id matching an attack prefab. Returns std::nullopt if none is found.
     * Then checks for an already cached version of the UnitAttack or creates a cached version if
     * none is found. Returns the associated attack for the specified id.
     */
    std::optional<UnitAttack> getUnitAttackByID(const int id);

    /*
     * Attempts to load all attackPrefabIDs using getUnitAttackByID(id) and returns a vector
     * containing all the successfully found unit attacks.
     */
    std::vector<UnitAttack> getAllUnitAttacksByID(const std::vector<int>& attackPrefabIDs);

    /*
     * Generates a new random enemy based on prefab data. If there are no enemy templates an
     * enemy with "ERROR" for their name is returned with 0s for all stats. For successful
     * template generated enemies they generate a name by combining the enemy type with a
     * randomly selected name associated with that enemy type if any exist.
     */
    Enemy getRandomEnemy();

    // Creates a player based on a randomly selected prefab and uses the specified playerName and position.
    Player getRandomPlayerPrefab(const std::string& playerName, const MapPosition& initialPlayerPosition);

    // Returns the filename of a random map. An empty string is returned if none are available.
    std::string getRandomMapFileName() const;

    // Outputs the full contents of the database in the same format it would have been read in.
    bool dumpDatabaseToFile(const std::string& fileName);

private:
    // Loaded enemy prefabs that can be turned into Enemy objects using getRandomEnemy().
    std::vector<EnemyPrefab> _enemyPrefabs;
    // Loaded enemy names that pair an enemyType key with a name value. Used by getRandomEnemy().
    std::multimap<std::string, std::string> _enemyTypeToNameOptionsMap;
    // Loaded attack types that can be turned into UnitAttack objects with getUnitAttackByID().
    std::map<int, AttackTypePrefab> _attackTypePrefabs;
    // Cached UnitAttack objects based on the types stored in _attackTypePrefabs.
    std::map<int, UnitAttack> _generatedAttackTypes;
    // Loaded player prefabs that can be used to create Player objects using getRandomPlayerPrefab().
    std::vector<PlayerPrefab> _playerPrefabs;
    // Loaded map file names that can be requested via getRandomMapFileName().
    std::vector<std::string> _mapFileNames;

    // Returns std::nullopt if no names were found for enemyType or a randomly selected name specific to the enemyType.
    std::optional<std::string> getNameForEnemyType(const std::string& enemyType);
    // Loads the specified file by reading one line at a time and passing it to insertDatabase().
    void loadAssetDatabase(const std::string& assetDatabaseFileName);
    // Checks the first word in the string and calls an appropriate function to insert if possible.
    void insertDatabase(const std::string& dataLine);
    // Validates an enemy name prefab has provided both an enemyType and enemyName then inserts.
    void insertEnemyNamePrefab(std::stringstream& lineStream);
    // Validates that an enemy prefab has a type, map char, health, mana, and min 1 attack types then inserts the prefab.
    void insertEnemyPrefab(std::stringstream& lineStream);
    // Validates that a player prefab has health, mana, and at least 1 attack type then inserts the prefab.
    void insertPlayerPrefab(std::stringstream& lineStream);
    /* Validates that the attack prefab has an id, min damage, max damage, crit chance, crit multiplier, mana cost,
        and attack name. Then inserts the prefab. */
    void insertAttackPrefab(std::stringstream& lineStream);
    // Validates that the map has a map file name and inserts it into the map list.
    void insertMapFileName(std::stringstream& lineStream);

    // Generic function to read into a variable of any type with an error showing what was expected if it fails and returns false.
    template<class T>
    bool readExpectedData(std::stringstream& lineStream, T& output, const std::string& expectedType);
    // Reads an entire line of input and trims all white space. Returns false with an error if output is empty.
    static bool readLine(std::stringstream& lineStream, std::string& output, const std::string& expectedType);
    // Reads in as many ints as possible storing them into the vector. Returns false with an error if requireOneMin is true and output is empty.
    static bool readAllInts(std::stringstream& lineStream, std::vector<int>& output, const std::string& expectedType, const bool requireOneMin);
};


#endif //RPGTEXTCPP_ASSETDATABASE_H
