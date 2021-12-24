//
// Created by Peter on 24/12/2021.
//

#ifndef RPGTEXTCPP_PLAYER_H
#define RPGTEXTCPP_PLAYER_H

#include <iostream>

#define PLAYER_NAME_MINLENGTH 3
#define PLAYER_NAME_MAXLENGTH 20
#define PLAYER_NAME_DEFAULT "NAME_NOT_SET"

class Player {
public:
    Player() : Player(PLAYER_NAME_DEFAULT) {}
    Player(const std::string playerName);
    std::string getName() const;
    void setName(const std::string playerName);
    friend std::ostream& operator<< (std::ostream& out, const Player& player);
    friend std::istream& operator>> (std::istream& in, Player& player);

private:
    std::string playerName;
};

/*
 * Creates a player using cin and continues asking for new names
 * until a valid name is entered. Requires names are between
 * PLAYER_NAME_MIN_LENGTH and PLAYER_NAME_MAX_LENGTH inclusively.
 * Also requires names to be only alpha or numeric characters.
 * Validation is handled via hasValidPlayerName(player).
 *
 * @return Returns a player object with a valid name.
 */
Player createPlayer();

/*
 * Validates if the provided Player object has a valid name.
 * For a name to be valid it must have a length between
 * PLAYER_NAME_MIN_LENGTH and PLAYER_NAME_MAX_LENGTH inclusively.
 * Then validates every character is alphanumeric.
 * If any of those three conditions are not met (in order),
 * the subsequent testing is halted, an error is shown via cout
 * and the method returns false.
 *
 * @return Returns true if the name is a valid length and only alphanumeric.
 */
bool hasValidPlayerName(const Player player);

#endif //RPGTEXTCPP_PLAYER_H
