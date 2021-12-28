//
// Created by Peter on 26/12/2021.
//

#include "Encounter.h"

Encounter::Encounter(const MapPosition &mapPosition) {
    _mapPosition = mapPosition;
    _enemyList.push_back(Enemy("Test", '#', 100));
}

void Encounter::playEncounterTurn(Player &player) {
    std::cout << "PLAYING ENCOUNTER" << std::endl;
    /*std::optional<UnitAttack> playerAttack = player.chooseAttack();
    if(playerAttack.has_value()) {
        applyAttack(playerAttack.value(), player, _enemyList.at(0));
    }*/
}

bool Encounter::isWon() const {
    return _enemyList.empty();
}

char Encounter::getEncounterChar() const {
    if(isWon()) {
        return '%';
    }
    return _enemyList.at(0).getMapOverlayChar();
}

bool Encounter::applyAttack(const UnitAttack &unitAttack, const CombatUnit &attacker, CombatUnit &target) {
    return false;
}

MapPosition Encounter::getMapPosition() const {
    return _mapPosition;
}
