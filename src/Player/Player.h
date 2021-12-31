//
// Created by Peter on 24/12/2021.
//

#ifndef RPGTEXTCPP_PLAYER_H
#define RPGTEXTCPP_PLAYER_H

#include <iostream>
#include "../Enemies/CombatUnit.h"
#include "../WorldMap/MapPosition.h"

#define PLAYER_NAME_MINLENGTH 3
#define PLAYER_NAME_MAXLENGTH 20
#define PLAYER_NAME_DEFAULT "NAME_NOT_SET"
#define PLAYER_HEAL_HP_MULTIPLIER 0.3
#define PLAYER_MANA_RESTORE_MULTIPLIER 0.8

// Represents a Player with a name and their other properties for combat and map position.
class Player : public CombatUnit {
public:
    Player(const std::string& playerName, const size_t initialMaxHealth, const size_t initialMaxMana,
                     const std::vector<UnitAttack>& attackTypes, const MapPosition& initialPlayerPosition)
                     : CombatUnit(playerName, '@', initialMaxHealth, initialMaxMana, attackTypes),
                       _playerPosition(initialPlayerPosition) {}

    void setPlayerPosition(const MapPosition playerPosition);
    MapPosition getPlayerPosition() const;

    void recoverStats();

    std::optional<UnitAttack> chooseAttack() override;

private:
    MapPosition _playerPosition;
};

/*
 * Creates a player using cin and continues asking for new names
 * until a valid name is entered. Requires names are between
 * PLAYER_NAME_MIN_LENGTH and PLAYER_NAME_MAX_LENGTH inclusively.
 * Also requires names to be only alpha or numeric characters.
 * Validation is handled via hasValidPlayerName().
 *
 * @return Returns a string with a valid name.
 */
std::string choosePlayerName();

/*
 * Validates if the provided string is a valid name.
 * For a name to be valid it must have a length between
 * PLAYER_NAME_MIN_LENGTH and PLAYER_NAME_MAX_LENGTH inclusively.
 * Then validates every character is alphanumeric.
 * If any of those three conditions are not met (in order),
 * the subsequent testing is halted, an error is shown via cout
 * and the method returns false.
 *
 * @return Returns true if the name is a valid length and only alphanumeric.
 */
bool isValidPlayerName(const std::string& playerName);

#endif //RPGTEXTCPP_PLAYER_H
