//
// Created by Peter on 26/12/2021.
//

#include <iostream>
#include "CombatUnit.h"

CombatUnit::CombatUnit(const std::string unitName, const char mapOverlayChar, const size_t initialMaxHealth)
    : _unitHealth(initialMaxHealth), _unitMana(100)
{
    setName(unitName);
    _mapOverlayChar = mapOverlayChar;
    _attackTypes.emplace_back();
}

void CombatUnit::setName(const std::string unitName) {
    this->_unitName = unitName;
}

std::string CombatUnit::getName() const {
    return _unitName;
}

UnitHealth & CombatUnit::getUnitHealth() {
    return _unitHealth;
}

std::optional<UnitAttack> CombatUnit::getUnitAttack(const size_t attackID) const {
    if(attackID >= _attackTypes.size()) {
        //std::cerr << "INVALID ATTACK: " << attackID;
        return std::nullopt;
    }
    return _attackTypes.at(attackID);
}

std::optional<UnitAttack> CombatUnit::getRandomUnitAttack() const {
    return getUnitAttack(rand() % getAttackCount());
}

size_t CombatUnit::getAttackCount() const {
    return _attackTypes.size();
}


std::ostream& operator<< (std::ostream& out, const CombatUnit& combatUnit) {
    out << combatUnit.getName() << " has " << combatUnit._unitHealth << " HP and ";
    out << combatUnit._unitMana << " Mana.";
    return out;
}

char CombatUnit::getMapOverlayChar() const {
    return _mapOverlayChar;
}
