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
    Encounter(const MapPosition& mapPosition);
    void playEncounterTurn(Player& player);
    bool isWon() const;
    char getEncounterChar() const;
    MapPosition getMapPosition() const;

private:
    MapPosition _mapPosition;
    std::vector<Enemy> _enemyList;

    bool applyAttack(const UnitAttack& unitAttack, const CombatUnit& attacker, CombatUnit& target);
};


#endif //RPGTEXTCPP_ENCOUNTER_H
