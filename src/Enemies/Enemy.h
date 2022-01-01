//
// Created by Peter on 26/12/2021.
//

#ifndef RPGTEXTCPP_ENEMY_H
#define RPGTEXTCPP_ENEMY_H

#include "CombatUnit.h"

/*
 * Enemy overrides the basic CombatUnit by having it use a random usable attack when chooseAttack is called.
 */
class Enemy : public CombatUnit {
public:
    /*
     * Initialises an enemy with the required properties.
     *
     * @param unitName The name of this enemy.
     * @param mapOverlayChar The character used to represent this enemy on the map.
     * @param initialMaxHealth The initial health maximum for this enemy.
     * @param initialMaxMana The initial mana maximum for this enemy.
     * @param attackTypes One or more attacks that this enemy can use in combat.
     */
    Enemy(const std::string& enemyName, const char mapOverlayChar, const size_t initialMaxHealth,
          const size_t initialMaxMana, const std::vector<UnitAttack>& attackTypes)
                        : CombatUnit(enemyName, mapOverlayChar, initialMaxHealth, initialMaxMana, attackTypes) {};

    // Returns either a random usable attack based on current mana or std::nullopt.
    std::optional<UnitAttack> chooseAttack() override;
};


#endif //RPGTEXTCPP_ENEMY_H
