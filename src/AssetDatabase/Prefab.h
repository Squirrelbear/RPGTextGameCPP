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
    Prefab(const PrefabType& prefabType, const int prefabID) : _prefabType(prefabType), _prefabID(prefabID) {}
    PrefabType getPrefabType() const;
    int getPrefabID() const;

private:
    PrefabType _prefabType;
    int _prefabID;
};

class AttackTypePrefab : public Prefab {
public:
    // Empty constructor required for map to use []
    AttackTypePrefab() : Prefab(PrefabType::ATTACK_TYPE, 0) {}
    AttackTypePrefab(const int prefabID, const std::string& attackName, const int& damageMin, const int& damageMax,
                     const float& criticalChance, const float& criticalDamageMultiplier, const size_t& manaCost)
                     : Prefab(PrefabType::ATTACK_TYPE, prefabID), attackName(attackName), damageMin(damageMin),
                       damageMax(damageMax), criticalChance(criticalChance),
                       criticalDamageMultiplier(criticalDamageMultiplier), manaCost(manaCost) {}

    std::string attackName;
    int damageMin;
    int damageMax;
    float criticalChance;
    float criticalDamageMultiplier;
    size_t manaCost;
};

class EnemyPrefab : public Prefab {
public:
    EnemyPrefab(const int prefabID, const std::string& enemyType, const char mapOverlayChar,
                const size_t initialMaxHealth, const size_t initialMaxMana, std::vector<int> attackTypes)
                : Prefab(PrefabType::ENEMY, prefabID), enemyType(enemyType), mapOverlayChar(mapOverlayChar),
                    initialMaxHealth(initialMaxHealth), initialMaxMana(initialMaxMana), attackTypes(attackTypes) {}

    std::string enemyType;
    char mapOverlayChar;
    size_t initialMaxHealth;
    size_t initialMaxMana;
    std::vector<int> attackTypes;
};

class PlayerPrefab : public Prefab {
public:
    PlayerPrefab(const int prefabID, const size_t initialMaxHealth, const size_t initialMaxMana, std::vector<int> attackTypes)
                    : Prefab(PrefabType::PLAYER, prefabID), initialMaxHealth(initialMaxHealth),
                      initialMaxMana(initialMaxMana), attackTypes(attackTypes) {}

    const size_t initialMaxHealth;
    const size_t initialMaxMana;
    const std::vector<int> attackTypes;
};


#endif //RPGTEXTCPP_PREFAB_H