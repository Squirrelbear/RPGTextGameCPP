//
// Created by Peter on 30/12/2021.
//

#ifndef RPGTEXTCPP_ASSETDATABASE_H
#define RPGTEXTCPP_ASSETDATABASE_H


#include <map>
#include "Prefab.h"
#include "../Enemies/UnitAttack.h"
#include "../Enemies/Enemy.h"

class AssetDatabase {
public:
    AssetDatabase();

    std::optional<UnitAttack> getUnitAttackByID(const int id);
    std::vector<UnitAttack> getAllUnitAttacksByID(const std::vector<int> attackPrefabIDs);
    Enemy getRandomEnemy();
    PlayerPrefab getRandomPlayerPrefab();

private:
    std::map<int, EnemyPrefab> _enemyPrefabs;
    std::map<int, AttackTypePrefab> _attackTypePrefabs;
    std::map<int, UnitAttack> _generatedAttackTypes;
    std::map<int, PlayerPrefab> _playerPrefabs;
};


#endif //RPGTEXTCPP_ASSETDATABASE_H
