//
// Created by Peter on 30/12/2021.
//

#ifndef RPGTEXTCPP_PREFAB_H
#define RPGTEXTCPP_PREFAB_H

#include <iostream>
#include <vector>

enum PrefabType {ATTACK_TYPE, ENEMY, PLAYER};

class Prefab {
public:
    Prefab(const Prefab& prefab) : Prefab(prefab._prefabType, prefab._prefabType) {}
    Prefab(const PrefabType& prefabType, const int prefabID = 0) : _prefabType(prefabType), _prefabID(prefabID) {}

    PrefabType _prefabType;
    int _prefabID;
};

class AttackTypePrefab : public Prefab {
public:
    // Empty constructor required for map to use []
    AttackTypePrefab() : Prefab(PrefabType::ATTACK_TYPE) {}
    AttackTypePrefab(const int prefabID, const std::string& attackName, const int& damageMin, const int& damageMax,
                     const float& criticalChance, const float& criticalDamageMultiplier, const unsigned int& manaCost)
                     : Prefab(PrefabType::ATTACK_TYPE, prefabID), attackName(attackName), damageMin(damageMin),
                       damageMax(damageMax), criticalChance(criticalChance),
                       criticalDamageMultiplier(criticalDamageMultiplier), manaCost(manaCost) {}

    friend std::ostream& operator<< (std::ostream& out, const AttackTypePrefab& attackTypePrefab);

    std::string attackName;
    int damageMin;
    int damageMax;
    float criticalChance;
    float criticalDamageMultiplier;
    unsigned int manaCost;
};

class EnemyPrefab : public Prefab {
public:
    EnemyPrefab(const int prefabID, const std::string& enemyType, const char mapOverlayChar,
                const unsigned int initialMaxHealth, const unsigned int initialMaxMana, std::vector<int>& attackTypes)
                : Prefab(PrefabType::ENEMY, prefabID), enemyType(enemyType), mapOverlayChar(mapOverlayChar),
                    initialMaxHealth(initialMaxHealth), initialMaxMana(initialMaxMana), attackTypes(attackTypes) {}

    friend std::ostream& operator<< (std::ostream& out, const EnemyPrefab& enemyPrefab);

    std::string enemyType;
    char mapOverlayChar;
    unsigned int initialMaxHealth;
    unsigned int initialMaxMana;
    std::vector<int> attackTypes;
};

class PlayerPrefab : public Prefab {
public:
    PlayerPrefab(const int prefabID, const unsigned int initialMaxHealth, const unsigned int initialMaxMana,
                 std::vector<int>& attackTypes)
                    : Prefab(PrefabType::PLAYER, prefabID), initialMaxHealth(initialMaxHealth),
                      initialMaxMana(initialMaxMana), attackTypes(attackTypes) {}

    friend std::ostream& operator<< (std::ostream& out, const PlayerPrefab& playerPrefab);

    const unsigned int initialMaxHealth;
    const unsigned int initialMaxMana;
    const std::vector<int> attackTypes;
};


#endif //RPGTEXTCPP_PREFAB_H
