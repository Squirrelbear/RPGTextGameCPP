//
// Created by Peter on 24/12/2021.
//

#include "Player.h"
#include <algorithm>

std::optional<UnitAttack> Player::chooseAttack() {
    std::vector<int> usableAttacks = getUsableAttacks();
    if(usableAttacks.empty()) {
        std::cout << "You have no usable attacks." << std::endl;
        return std::nullopt;
    } else if(usableAttacks.size() == 1) {
        std::cout << "You only had one usable attack so it was used." << std::endl;
        return getUnitAttack(usableAttacks.at(0));
    }

    int choice = -1;
    std::string playerInput;
    do {
        std::cout << "Select one of the following valid ability choices by entering its number." << std::endl;
        for(auto& attackID : usableAttacks) {
            std::cout << (attackID+1) << ". " << getUnitAttack(attackID).value() << std::endl;
        }
        std::cout << "Enter choice: ";
        std::getline(std::cin, playerInput);
        try {
            choice = std::stoi(playerInput);
        } catch(...) {
            std::cout << "Invalid input. Please enter a number matching an option." << std::endl;
            continue;
        }
        --choice;
    } while(std::find(usableAttacks.begin(), usableAttacks.end(), choice) == usableAttacks.end());
    return getUnitAttack(choice);
}

MapPosition Player::getPlayerPosition() const {
    return _playerPosition;
}

void Player::setPlayerPosition(const MapPosition playerPosition) {
    _playerPosition = playerPosition;
}

void Player::recoverStats() {
    if(getUnitHealth().getStatValue() == getUnitHealth().getStatMax()) {
        std::cout << "Heal was cast, but your health was already full." << std::endl;
    } else {
        int actualHealingDone = getUnitHealth().increaseStatBy(
                (int)(getUnitHealth().getStatMax() * PLAYER_HEAL_HP_MULTIPLIER));
        std::cout << "You have been healed for " << actualHealingDone << " bringing your health to "
                  << getUnitHealth() << "." << std::endl;
    }

    if(getUnitMana().getStatValue() == getUnitMana().getStatMax()) {
        std::cout << "Restore Mana was cast, but your mana was already full." << std::endl;
    } else {
        int actualRestoreDone = getUnitMana().increaseStatBy(
                (int)(getUnitMana().getStatMax() * PLAYER_MANA_RESTORE_MULTIPLIER));
        std::cout << "You have been restored for " << actualRestoreDone << " bringing your mana to "
                  << getUnitMana() << "." << std::endl;
    }
}

std::string choosePlayerName() {
    std::string playerName;
    do {
        std::cout << "Enter your name: ";
        std::cin >> playerName;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while(!isValidPlayerName(playerName));
    return playerName;
}

bool isValidPlayerName(const std::string &playerName) {
    if(playerName.length() < PLAYER_NAME_MINLENGTH) {
        std::cout << "Your chosen name is too short. Name must be " << PLAYER_NAME_MINLENGTH << " to "
                  << PLAYER_NAME_MAXLENGTH << "." << std::endl;
        return false;
    } else if(playerName.length() > PLAYER_NAME_MAXLENGTH) {
        std::cout << "Your chosen name is too long. Name must be " << PLAYER_NAME_MINLENGTH << " to "
                  << PLAYER_NAME_MAXLENGTH << "." << std::endl;
        return false;
    } else if(playerName == PLAYER_NAME_DEFAULT) {
        std::cout << "Invalid name entered. Try again." << std:: endl;
        return false;
    }

    for(int i = 0; i < playerName.length(); i++) {
        if(!isalnum(playerName.at(i))) {
            std::cout << "Your name contains invalid characters. Only a-z A-Z and 0-9 are allowed." << std::endl;
            return false;
        }
    }

    return true;
}

