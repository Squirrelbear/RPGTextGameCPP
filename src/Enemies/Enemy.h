//
// Created by Peter on 26/12/2021.
//

#ifndef RPGTEXTCPP_ENEMY_H
#define RPGTEXTCPP_ENEMY_H

#include "CombatUnit.h"

class Enemy : CombatUnit {
public:
    UnitAttack chooseAttack();

private:
    std::string _enemyName;
};


#endif //RPGTEXTCPP_ENEMY_H
