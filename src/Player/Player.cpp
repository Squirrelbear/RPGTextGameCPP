//
// Created by Peter on 24/12/2021.
//

#include "Player.h"

bool Player::hasValidPlayerName() const {
    if(getName().length() < PLAYER_NAME_MINLENGTH) {
        std::cout << "Your chosen name is too short. Name must be " << PLAYER_NAME_MINLENGTH << " to "
                  << PLAYER_NAME_MAXLENGTH << "." << std::endl;
        return false;
    } else if(getName().length() > PLAYER_NAME_MAXLENGTH) {
        std::cout << "Your chosen name is too long. Name must be " << PLAYER_NAME_MINLENGTH << " to "
                  << PLAYER_NAME_MAXLENGTH << "." << std::endl;
        return false;
    } else if(getName() == PLAYER_NAME_DEFAULT) {
        std::cout << "Invalid name entered. Try again." << std:: endl;
        return false;
    }

    for(int i = 0; i < getName().length(); i++) {
        if(!isalnum(getName().at(i))) {
            std::cout << "Your name contains invalid characters. Only a-z A-Z and 0-9 are allowed." << std::endl;
            return false;
        }
    }

    return true;
}

std::istream& operator>> (std::istream& in, Player& player) {
    std::string nameInput;
    in >> nameInput;
    player.setName(nameInput);

    return in;
}

std::optional<UnitAttack> Player::chooseAttack() {
    // TODO
    return UnitAttack();
}

Player createPlayer() {
    Player player;
    do {
        std::cout << "Enter your name: ";
        std::cin >> player;
    } while(!player.hasValidPlayerName());
    return player;
}

