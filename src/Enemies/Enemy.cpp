//
// Created by Peter on 26/12/2021.
//

#include "Enemy.h"

std::optional<UnitAttack> Enemy::chooseAttack() {
    return getRandomUnitAttack();
}
