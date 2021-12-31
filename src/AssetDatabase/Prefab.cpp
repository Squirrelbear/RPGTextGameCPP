//
// Created by Peter on 30/12/2021.
//

#include "Prefab.h"

PrefabType Prefab::getPrefabType() const {
    return _prefabType;
}

int Prefab::getPrefabID() const {
    return _prefabID;
}

std::ostream &operator<<(std::ostream &out, const AttackTypePrefab &attackTypePrefab) {
    out << attackTypePrefab.damageMin << " "
        << attackTypePrefab.damageMax << " " << attackTypePrefab.criticalChance << " "
        << attackTypePrefab.criticalDamageMultiplier << " " << attackTypePrefab.manaCost << " "
        << attackTypePrefab.attackName << std::endl;

    return out;
}

std::ostream &operator<<(std::ostream &out, const EnemyPrefab &enemyPrefab) {
    out << enemyPrefab.enemyType << " " << enemyPrefab.mapOverlayChar << " "
        << enemyPrefab.initialMaxHealth << " " << enemyPrefab.initialMaxMana << " ";

    for(auto& attack : enemyPrefab.attackTypes) {
        out << attack << " ";
    }
    out << std::endl;

    return out;
}

std::ostream &operator<<(std::ostream &out, const PlayerPrefab &playerPrefab) {
    out << playerPrefab.initialMaxHealth << " " << playerPrefab.initialMaxMana << " ";

    for(auto& attack : playerPrefab.attackTypes) {
        out << attack << " ";
    }
    out << std::endl;

    return out;
}
