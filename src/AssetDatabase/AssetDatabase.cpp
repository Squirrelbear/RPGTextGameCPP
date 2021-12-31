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
