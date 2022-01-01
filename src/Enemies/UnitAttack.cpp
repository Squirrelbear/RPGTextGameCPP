//
// Created by Peter on 26/12/2021.
//

#include "UnitAttack.h"
#include <iostream>

size_t UnitAttack::getManaCost() const {
    return _manaCost;
}

UnitAttack::UnitAttack(const std::string &attackName, const int &damageMin, const int &damageMax,
                       const float &criticalChance, const float &criticalDamageMultiplier, const size_t &manaCost)
           : _attackName(attackName), _baseDamageMin(damageMin), _baseDamageMax(damageMax), _criticalChance(criticalChance),
             _criticalDamageMultiplier(criticalDamageMultiplier), _manaCost(manaCost) {

}

int UnitAttack::getRandomBaseDamage() const {
    return rand() % (_baseDamageMax - _baseDamageMin + 1) + _baseDamageMin;
}

bool UnitAttack::isCriticalDamage() const {
    return rand() % 100 < _criticalChance;
}

int UnitAttack::getCriticalModifiedDamage(const int &baseDamage) const {
    return static_cast<int>(baseDamage * _criticalDamageMultiplier);
}

std::string UnitAttack::getName() const {
    return _attackName;
}

std::ostream &operator<<(std::ostream &out, const UnitAttack &unitAttack) {
    out << unitAttack.getName() << " (" << unitAttack._baseDamageMin;
    if(unitAttack._baseDamageMin != unitAttack._baseDamageMax) {
        out << " to " << unitAttack._baseDamageMax;
    }
    out << " damage) " << unitAttack._criticalChance << "% chance of x";
    out << unitAttack._criticalDamageMultiplier << " Mana Cost: " << unitAttack._manaCost;
    return out;
}


