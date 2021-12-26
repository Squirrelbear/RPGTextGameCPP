//
// Created by Peter on 26/12/2021.
//

#include <iostream>
#include "CombatUnit.h"

CombatUnit::CombatUnit() {
    _attackTypes.emplace_back();
}

UnitHealth & CombatUnit::getUnitHealth() {
    return _unitHealth;
}

UnitAttack CombatUnit::getUnitAttack(const size_t attackID) const {
    if(attackID >= _attackTypes.size()) {
        std::cerr << "INVALID ATTACK: " << attackID;
    }
    return _attackTypes.at(attackID);
}

UnitAttack CombatUnit::getRandomUnitAttack() const {
    return getUnitAttack(rand() % getAttackCount());
}

size_t CombatUnit::getAttackCount() const {
    return _attackTypes.size();
}