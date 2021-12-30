//
// Created by Peter on 30/12/2021.
//

#include "AssetDatabase.h"

AssetDatabase::AssetDatabase() {

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
    // TODO
    return Enemy("", 0, 0);
}

PlayerPrefab AssetDatabase::getRandomPlayerPrefab() {
    // TODO
    return _playerPrefabs[0];
}
