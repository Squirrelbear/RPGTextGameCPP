//
// Created by Peter on 26/12/2021.
//

#ifndef RPGTEXTCPP_ENCOUNTER_H
#define RPGTEXTCPP_ENCOUNTER_H

#include "../WorldMap/MapPosition.h"
#include "Enemy.h"
#include "../Player/Player.h"

class Encounter {
public:
    Encounter(const MapPosition& mapPosition, const std::vector<Enemy>& enemyList);
    void playEncounterTurn(Player& player);
    bool isWon() const;
    char getEncounterChar() const;
    MapPosition getMapPosition() const;

private:
    int _turnCount;
    MapPosition _mapPosition;
    std::vector<Enemy> _enemyList;

    bool playCombatUnitTurn(CombatUnit& attackerUnit, CombatUnit& targetUnit);
    bool applyAttack(UnitAttack& unitAttack, CombatUnit& attacker, CombatUnit& target);
};


#endif //RPGTEXTCPP_ENCOUNTER_H
