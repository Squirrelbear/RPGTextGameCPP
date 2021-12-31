//
// Created by Peter on 30/12/2021.
//

#include "AssetDatabase.h"
#include "../Utilities/StringUtility.h"
#include <fstream>
#include <sstream>

AssetDatabase::AssetDatabase(const std::string& assetDatabaseFile) {
    loadAssetDatabase(assetDatabaseFile);
}

std::optional<UnitAttack> AssetDatabase::getUnitAttackByID(const int id) {
    // ID is not valid
    if(_attackTypePrefabs.count(id) == 0) {
        return std::nullopt;
    }

    // check if it was generated previously and do so if it was not.
    if(_generatedAttackTypes.count(id) == 0) {
        AttackTypePrefab& attack = _attackTypePrefabs[id];
        _generatedAttackTypes[id] = UnitAttack(attack.attackName, attack.damageMin, attack.damageMax,
                                               attack.criticalChance, attack.criticalDamageMultiplier, attack.manaCost);
    }
    return _generatedAttackTypes[id];
}

std::vector<UnitAttack> AssetDatabase::getAllUnitAttacksByID(const std::vector<int> attackPrefabIDs) {
    std::vector<UnitAttack> result;
    for(auto& id : attackPrefabIDs) {
        std::optional<UnitAttack> unitAttack = getUnitAttackByID(id);
        if(unitAttack.has_value()) {
            result.emplace_back(unitAttack.value());
        } else {
            std::cout << "ERROR: Failed to load attack prefab ID number " << id << std::endl;
        }
    }
    return result;
}

Enemy AssetDatabase::getRandomEnemy() {
    if(_enemyPrefabs.size() == 0) {
        std::cout << "ERROR: No enemy prefabs found." << std::endl;
        return Enemy("ERROR", 0, 0, 0, std::vector<UnitAttack>());
    }
    EnemyPrefab prefab = _enemyPrefabs.at(rand() % _enemyPrefabs.size());
    std::optional<std::string> uniqueName = getNameForEnemyType(prefab.enemyType);

    std::string fullName = prefab.enemyType + ((uniqueName.has_value()) ? " " + uniqueName.value() : "");
    Enemy result = Enemy(fullName, prefab.mapOverlayChar, prefab.initialMaxHealth, prefab.initialMaxMana,
                         getAllUnitAttacksByID(prefab.attackTypes));
    return result;
}

Player AssetDatabase::getRandomPlayerPrefab(const std::string& playerName, const MapPosition& initialPlayerPosition) {
    PlayerPrefab playerPrefab = _playerPrefabs.at(rand() % _playerPrefabs.size());
    return Player(playerName, playerPrefab.initialMaxHealth, playerPrefab.initialMaxMana,
                  getAllUnitAttacksByID(playerPrefab.attackTypes), initialPlayerPosition);
}

std::optional<std::string> AssetDatabase::getNameForEnemyType(const std::string &enemyType) {
    typedef std::multimap<std::string, std::string>::iterator MMAPIterator;
    std::pair<MMAPIterator, MMAPIterator> searchResult = _enemyTypeToNameOptionsMap.equal_range(enemyType);
    int count = std::distance(searchResult.first, searchResult.second);
    if(count == 0) {
        return std::nullopt;
    }

    // Iterate from the beginning to a random element within the count and then return it.
    MMAPIterator it = searchResult.first;
    int randIndex = rand() % count;
    for(int i = 0; i < randIndex; i++, it++);

    return it->second;
}

void AssetDatabase::loadAssetDatabase(const std::string &assetDatabaseFileName) {
    std::string currentLine;
    std::ifstream databaseFile(assetDatabaseFileName);
    if(!databaseFile.is_open()) {
        std::cerr << "Critical error! Could not open asset file: " << assetDatabaseFileName << std::endl;
        return;
    }
    while(std::getline(databaseFile, currentLine)) {
        insertDatabase(currentLine);
    }
    databaseFile.close();
}

void AssetDatabase::insertDatabase(const std::string& dataLine) {
    std::stringstream lineStream(dataLine);
    std::string dataType;
    lineStream >> dataType;

    if(lineStream.fail()) {
        return;
    } else if(dataType == "ENEMYNAME") {
        insertEnemyNamePrefab(lineStream);
    } else if(dataType == "PLAYER") {
        insertPlayerPrefab(lineStream);
    } else if(dataType == "ENEMY") {
        insertEnemyPrefab(lineStream);
    } else if(dataType == "ATTACK") {
        insertAttackPrefab(lineStream);
    } else if(dataType == "MAP") {
        insertMapFileName(lineStream);
    }
}

void AssetDatabase::insertEnemyNamePrefab(std::stringstream &lineStream) {
    std::string enemyType, enemyName;
    if(!readExpectedData(lineStream, enemyType, "enemy type")
       || !readLine(lineStream, enemyName, "enemy name")) {
        return;
    }
    // Successfully read required data: insert element.
    _enemyTypeToNameOptionsMap.insert(std::pair<std::string,std::string>(enemyType, enemyName));
}

void AssetDatabase::insertEnemyPrefab(std::stringstream &lineStream) {
    int prefabID = _enemyPrefabs.size();
    std::string enemyType;
    char mapOverlayChar;
    size_t initialMaxHealth, initialMaxMana;
    std::vector<int> attackTypes;

    if(!readExpectedData(lineStream, enemyType, "enemy type")
       || !readExpectedData(lineStream, mapOverlayChar, "map overlay char")
       || !readExpectedData(lineStream, initialMaxHealth, "initial max health")
       || !readExpectedData(lineStream, initialMaxMana, "initial max mana")
       || !readAllInts(lineStream, attackTypes, "attack types", true)) {
        return;
    }
    // Successfully read required data: insert element.
    _enemyPrefabs.emplace_back(EnemyPrefab(prefabID, enemyType, mapOverlayChar, initialMaxHealth,
                                           initialMaxMana, attackTypes));
}

void AssetDatabase::insertPlayerPrefab(std::stringstream &lineStream) {
    int prefabID = _playerPrefabs.size();
    size_t initialMaxHealth, initialMaxMana;
    std::vector<int> attackTypes;

    if(!readExpectedData(lineStream, initialMaxHealth, "initial max health")
       || !readExpectedData(lineStream, initialMaxMana, "initial max mana")
       || !readAllInts(lineStream, attackTypes, "attack types", true)) {
        return;
    }
    // Successfully read required data: insert element.
    _playerPrefabs.emplace_back(PlayerPrefab(prefabID, initialMaxHealth, initialMaxMana, attackTypes));
}

void AssetDatabase::insertAttackPrefab(std::stringstream &lineStream) {
    int prefabID, damageMin, damageMax;
    float criticalChance, criticalDamageMultiplier;
    size_t manaCost;
    std::string attackName;

    if(!readExpectedData(lineStream, prefabID, "attack id")
       || !readExpectedData(lineStream, damageMin, "damage min")
       || !readExpectedData(lineStream, damageMax, "damage max")
       || !readExpectedData(lineStream, criticalChance, "critical chance")
       || !readExpectedData(lineStream, criticalDamageMultiplier, "critical damage multiplier")
       || !readExpectedData(lineStream, manaCost, "mana cost")
       || !readLine(lineStream, attackName, "attack name")) {
        return;
    }
    if(damageMin > damageMax) {
        std::cerr << "Damage min is greater than damage max for this attack. " << prefabID << " ";
        std::cerr << attackName << ".";
        return;
    }
    AttackTypePrefab test(prefabID, attackName, damageMin, damageMax,
                     criticalChance, criticalDamageMultiplier,
                     manaCost);
    // Successfully read required data: insert element.
    _attackTypePrefabs.insert_or_assign(prefabID, test);
}

template<class T>
bool AssetDatabase::readExpectedData(std::stringstream &lineStream, T& output, const std::string &expectedType) {
    lineStream >> output;
    if(lineStream.fail()) {
        std::cerr << "Failed to read expected " << expectedType << "." << std::endl;
        return false;
    }
    return true;
}

bool AssetDatabase::readLine(std::stringstream &lineStream, std::string &output, const std::string &expectedType) {
    std::getline(lineStream, output);
    trim(output);
    if(output.empty()) {
        std::cerr << "Failed to read expected " << expectedType << "." << std::endl;
        return false;
    }
    return true;
}

bool AssetDatabase::readAllInts(std::stringstream &lineStream, std::vector<int> &output, const std::string &expectedType,
                           const bool requireOneMin) {
    int input;
    while(lineStream >> input) {
        output.emplace_back(input);
    }
    if(requireOneMin && output.empty()) {
        std::cerr << "Failed to find at least one attack type for enemy." << std::endl;
        return false;
    }
    return true;
}

void AssetDatabase::insertMapFileName(std::stringstream & lineStream) {
    std::string fileName;
    if(!readLine(lineStream, fileName, "map file name")) {
        return;
    }
    _mapFileNames.emplace_back(fileName);
}

std::string AssetDatabase::getRandomMapFileName() const {
    if(_mapFileNames.empty()) {
        std::cerr << "ERROR: No map filenames were defined." << std::endl;
        return "";
    }

    return _mapFileNames.at(rand() % _mapFileNames.size());
}
