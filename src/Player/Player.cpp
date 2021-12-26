//
// Created by Peter on 24/12/2021.
//

#include "Player.h"

Player::Player(const std::string playerName) {
    setName(playerName);
}

void Player::setName(const std::string playerName) {
    this->_playerName = playerName;
}

std::string Player::getName() const {
    return _playerName;
}

std::ostream& operator<< (std::ostream& out, const Player& player) {
    out << player._playerName;
    return out;
}

std::istream& operator>> (std::istream& in, Player& player) {
    std::string nameInput;
    in >> nameInput;
    player.setName(nameInput);

    return in;
}

UnitAttack Player::chooseAttack() {
    // TODO
    return UnitAttack();
}

Player createPlayer() {
    Player player;
    do {
        std::cout << "Enter your name: ";
        std::cin >> player;
    } while(!hasValidPlayerName(player));
    return player;
}

bool hasValidPlayerName(const Player player) {
    if(player.getName().length() < PLAYER_NAME_MINLENGTH) {
        std::cout << "Your chosen name is too short. Name must be " << PLAYER_NAME_MINLENGTH << " to "
                    << PLAYER_NAME_MAXLENGTH << "." << std::endl;
        return false;
    } else if(player.getName().length() > PLAYER_NAME_MAXLENGTH) {
        std::cout << "Your chosen name is too long. Name must be " << PLAYER_NAME_MINLENGTH << " to "
                  << PLAYER_NAME_MAXLENGTH << "." << std::endl;
        return false;
    } else if(player.getName() == PLAYER_NAME_DEFAULT) {
        std::cout << "Invalid name entered. Try again." << std:: endl;
        return false;
    }

    for(int i = 0; i < player.getName().length(); i++) {
        if(!isalnum(player.getName().at(i))) {
            std::cout << "Your name contains invalid characters. Only a-z A-Z and 0-9 are allowed." << std::endl;
            return false;
        }
    }

    return true;
}