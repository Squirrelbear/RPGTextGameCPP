//
// Created by Peter on 26/12/2021.
//

#include "Encounter.h"

Encounter::Encounter(const MapPosition &mapPosition, const std::vector<Enemy>& enemyList)
    : _enemyList(enemyList), _mapPosition(mapPosition), _turnCount(0) {}

void Encounter::playEncounterTurn(Player &player) {
    ++_turnCount;
    std::cout << "Beginning Encounter Turn " << _turnCount << std::endl;
    std::cout << player << std::endl;
    for(auto& enemy : _enemyList) {
        std::cout << enemy << std::endl;
    }
    bool killedTarget = playCombatUnitTurn(player, _enemyList.at(0));
    if(killedTarget) {
        _enemyList.erase(_enemyList.begin());
    }
    for(auto& enemy : _enemyList) {
        if(!player.getUnitHealth().hasZeroStat()) {
            playCombatUnitTurn(enemy, player);
        }
    }
    std::cout << std::endl;
}

bool Encounter::isWon() const {
    return _enemyList.empty();
}

char Encounter::getEncounterChar() const {
    if(isWon()) {
        // should never happen, but just in case the % is returned to satisfy all return paths.
        return '%';
    }
    return _enemyList.at(0).getMapOverlayChar();
}

bool Encounter::applyAttack(UnitAttack &unitAttack, CombatUnit &attacker, CombatUnit &target) {
    attacker.performAttackOn(unitAttack, target);
    if(target.getUnitHealth().hasZeroStat()) {
        std::cout << attacker.getName() << " defeated " << target.getName() << "!" << std::endl;
        return true;
    }
    return false;
}

MapPosition Encounter::getMapPosition() const {
    return _mapPosition;
}

bool Encounter::playCombatUnitTurn(CombatUnit &attackerUnit, CombatUnit &targetUnit) {
    std::optional<UnitAttack> selectedAttack = attackerUnit.chooseAttack();
    bool killedTarget = false;
    if(selectedAttack.has_value()) {
        killedTarget = applyAttack(selectedAttack.value(), attackerUnit, targetUnit);
    } else {
        std::cout << attackerUnit.getName() << " did not use any attack this round." << std::endl;
    }
    return killedTarget;
}
