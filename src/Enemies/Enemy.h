//
// Created by Peter on 26/12/2021.
//

#ifndef RPGTEXTCPP_ENEMY_H
#define RPGTEXTCPP_ENEMY_H

#include "CombatUnit.h"

class Enemy : public CombatUnit {
public:
    Enemy(const std::string& enemyName, const char mapOverlayChar, const size_t initialMaxHealth)
                        : CombatUnit(enemyName, mapOverlayChar, initialMaxHealth) {}
    std::optional<UnitAttack> chooseAttack() override;
};


#endif //RPGTEXTCPP_ENEMY_H
