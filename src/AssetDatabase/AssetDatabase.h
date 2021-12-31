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
    AssetDatabase();

    std::optional<UnitAttack> getUnitAttackByID(const int id);
    std::vector<UnitAttack> getAllUnitAttacksByID(const std::vector<int> attackPrefabIDs);
    Enemy getRandomEnemy();
    Player getRandomPlayerPrefab(const std::string& playerName, const MapPosition& initialPlayerPosition);

private:
    std::vector<EnemyPrefab> _enemyPrefabs;
    std::multimap<std::string, std::string> _enemyTypeToNameOptionsMap;
    std::map<int, AttackTypePrefab> _attackTypePrefabs;
    std::map<int, UnitAttack> _generatedAttackTypes;
    std::vector<PlayerPrefab> _playerPrefabs;

    std::optional<std::string> getNameForEnemyType(const std::string& enemyType);
};


#endif //RPGTEXTCPP_ASSETDATABASE_H
