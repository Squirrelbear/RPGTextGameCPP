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

class AssetDatabase {
public:
    AssetDatabase(const std::string& assetDatabaseFile);

    std::optional<UnitAttack> getUnitAttackByID(const int id);
    std::vector<UnitAttack> getAllUnitAttacksByID(const std::vector<int> attackPrefabIDs);
    Enemy getRandomEnemy();
    Player getRandomPlayerPrefab(const std::string& playerName, const MapPosition& initialPlayerPosition);
    std::string getRandomMapFileName() const;

private:
    std::vector<EnemyPrefab> _enemyPrefabs;
    std::multimap<std::string, std::string> _enemyTypeToNameOptionsMap;
    std::map<int, AttackTypePrefab> _attackTypePrefabs;
    std::map<int, UnitAttack> _generatedAttackTypes;
    std::vector<PlayerPrefab> _playerPrefabs;
    std::vector<std::string> _mapFileNames;

    std::optional<std::string> getNameForEnemyType(const std::string& enemyType);
    void loadAssetDatabase(const std::string& assetDatabaseFileName);
    void insertDatabase(const std::string& dataLine);
    void insertEnemyNamePrefab(std::stringstream& lineStream);
    void insertEnemyPrefab(std::stringstream& lineStream);
    void insertPlayerPrefab(std::stringstream& lineStream);
    void insertAttackPrefab(std::stringstream& lineStream);
    void insertMapFileName(std::stringstream& lineStream);

    template<class T>
    bool readExpectedData(std::stringstream& lineStream, T& output, const std::string& expectedType);
    bool readLine(std::stringstream& lineStream, std::string& output, const std::string& expectedType);
    bool readAllInts(std::stringstream& lineStream, std::vector<int>& output, const std::string& expectedType, const bool requireOneMin);

};


#endif //RPGTEXTCPP_ASSETDATABASE_H
