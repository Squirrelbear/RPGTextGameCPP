//
// Created by Peter on 30/12/2021.
//

#ifndef RPGTEXTCPP_PREFAB_H
#define RPGTEXTCPP_PREFAB_H

#include <iostream>
#include <vector>

enum PrefabType {AttackType, Enemy, Player};

class Prefab {
public:
    Prefab(const PrefabType& prefabType, const int prefabID) : _prefabType(prefabType), _prefabID(prefabID) {}
    PrefabType getPrefabType() const;
    int getPrefabID() const;

private:
    PrefabType _prefabType;
    int _prefabID;
};

class AttackTypePrefab : public Prefab {
public:
    AttackTypePrefab(const int prefabID, const std::string& attackName, const int& damageMin, const int& damageMax,
                     const float& criticalChance, const float& criticalDamageMultiplier, const size_t& manaCost)
                     : Prefab(PrefabType::AttackType, prefabID), attackName(attackName), damageMin(damageMin),
                       damageMax(damageMax), criticalChance(criticalChance),
                       criticalDamageMultiplier(criticalDamageMultiplier), manaCost(manaCost) {}

    const std::string attackName;
    const int damageMin;
    const int damageMax;
    const float criticalChance;
    const float criticalDamageMultiplier;
    const size_t manaCost;
};

class EnemyPrefab : public Prefab {
public:
    EnemyPrefab(const int prefabID, const std::string& enemyName, const char mapOverlayChar,
                const size_t initialMaxHealth, const size_t initialMaxMana, std::vector<int> attackTypes)
                : Prefab(PrefabType::Enemy, prefabID), enemyName(enemyName), mapOverlayChar(mapOverlayChar),
                    initialMaxHealth(initialMaxHealth), initialMaxMana(initialMaxMana), attackTypes(attackTypes) {}

    const std::string enemyName;
    const char mapOverlayChar;
    const size_t initialMaxHealth;
    const size_t initialMaxMana;
    const std::vector<int> attackTypes;
};

class PlayerPrefab : public Prefab {
public:
    PlayerPrefab(const int prefabID, const size_t initialMaxHealth, const size_t initialMaxMana, std::vector<int> attackTypes)
                    : Prefab(PrefabType::Player, prefabID), initialMaxHealth(initialMaxHealth),
                      initialMaxMana(initialMaxMana), attackTypes(attackTypes) {}

    const size_t initialMaxHealth;
    const size_t initialMaxMana;
    const std::vector<int> attackTypes;
};


#endif //RPGTEXTCPP_PREFAB_H
