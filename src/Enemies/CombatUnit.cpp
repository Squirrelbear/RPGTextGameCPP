//
// Created by Peter on 26/12/2021.
//

#include <iostream>
#include "CombatUnit.h"

CombatUnit::CombatUnit(const std::string& unitName, const char mapOverlayChar, const size_t initialMaxHealth,
                       const size_t initialMaxMana, const std::vector<UnitAttack>& attackTypes)
    : _unitName(unitName), _mapOverlayChar(mapOverlayChar), _unitHealth(initialMaxHealth), _unitMana(initialMaxMana),
        _attackTypes(attackTypes)
{
}

std::string CombatUnit::getName() const {
    return _unitName;
}

UnitHealth & CombatUnit::getUnitHealth() {
    return _unitHealth;
}

std::optional<UnitAttack> CombatUnit::getUnitAttack(const size_t attackID) const {
    if(attackID >= _attackTypes.size()) {
        return std::nullopt;
    }
    return _attackTypes.at(attackID);
}

std::optional<UnitAttack> CombatUnit::getRandomUnitAttack() {
    std::vector<int> usableAttacks = getUsableAttacks();
    if(usableAttacks.empty()) {
        return std::nullopt;
    }
    return getUnitAttack(usableAttacks.at(rand() % usableAttacks.size()));
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

void CombatUnit::performAttackOn(const UnitAttack &attack, CombatUnit &attackTarget) {
    consumeManaForAttack(attack);
    std::cout << getName() << "'s \"" << attack.getName() << "\" attack hit " << attackTarget.getName() << " for ";
    int damage = attack.getRandomBaseDamage();
    bool isCriticalHit = attack.isCriticalDamage();
    if(isCriticalHit) {
        damage = attack.getCriticalModifiedDamage(damage);
    }
    int actualDamage = attackTarget.getUnitHealth().decreaseStatBy(damage);
    std::cout << actualDamage << " damage. ";
    if(isCriticalHit) {
        std::cout << "Critical Hit! ";
    }
    if(actualDamage != damage) {
        std::cout << "Overkilled by " << (damage-actualDamage) << " damage!";
    }
    std::cout << std::endl;
}

UnitMana &CombatUnit::getUnitMana() {
    return _unitMana;
}

bool CombatUnit::canCastWithMana(const UnitAttack& attackType) {
    return getUnitMana().getStatValue() >= attackType.getManaCost();
}

void CombatUnit::consumeManaForAttack(const UnitAttack &attackType) {
    getUnitMana().decreaseStatBy(attackType.getManaCost());
}

std::vector<int> CombatUnit::getUsableAttacks() {
    std::vector<int> usableAttacks;
    int index = 0;
    for(auto& attack : _attackTypes) {
        if(canCastWithMana(attack)) {
            usableAttacks.push_back(index);
        }
        index++;
    }
    return usableAttacks;
}

bool CombatUnit::hasUsableAbility() {
    return !getUsableAttacks().empty();
}

