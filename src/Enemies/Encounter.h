//
// Created by Peter on 26/12/2021.
//

#ifndef RPGTEXTCPP_ENCOUNTER_H
#define RPGTEXTCPP_ENCOUNTER_H

#include "../WorldMap/MapPosition.h"
#include "Enemy.h"
#include "../Player/Player.h"

/*
 * An Encounter is used to represent a collection of one or more enemies
 * appearing on the map for a player to encounter and battle. Once an encounter is
 * started, playEncounterTurn() can be used to play through each turn and isWon()
 * will indicate if the encounter has been cleared successfully.
 */
class Encounter {
public:
    // Creates an encounter with one or more enemies at a specified map position.
    Encounter(const MapPosition& mapPosition, const std::vector<Enemy>& enemyList);

    /* Plays the current turn of an encounter by showing all the current statuses of the player and enemies.
     * Then the player is given a turn, followed by all enemies. If the player dies or all enemies are cleared
     * the encounter ends early. */
    void playEncounterTurn(Player& player);

    // Returns true if all enemies have been defeated.
    bool isWon() const;
    // Returns the character used to represent this encounter based on the first enemy in the list.
    char getEncounterChar() const;
    // Gets the position of this encounter on the map.
    MapPosition getMapPosition() const;

private:
    // The turn number of this encounter that increases each time playEncounterTurn() is called.
    int _turnCount;
    // The position of this encounter on the map.
    MapPosition _mapPosition;
    // A list of all enemies that are removed from the list as they are defeated.
    std::vector<Enemy> _enemyList;

    // Processes the attack selection of the specified attackerUnit and if an attack is selected it is used on the targetUnit.
    bool playCombatUnitTurn(CombatUnit& attackerUnit, CombatUnit& targetUnit);
    // Performs the chosen unitAttack from attacker onto target. Returns true if target is defeated.
    bool applyAttack(UnitAttack& unitAttack, CombatUnit& attacker, CombatUnit& target);
};


#endif //RPGTEXTCPP_ENCOUNTER_H
