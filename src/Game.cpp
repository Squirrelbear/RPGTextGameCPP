//
// Created by Peter on 26/12/2021.
//

#include "Game.h"

Game::Game(const std::string mapFileName, const Player& player)
    : _worldMap(mapFileName), _player(player) {
    std::cout << "Welcome " << _player.getName() << "! You are represented by the @ symbol." << std::endl;
}

void Game::gameLoop() {
    do {
        navigateMap();
        // TODO check which position
        //processEncounter(_encounters.at(0));
    } while(!isGameOver() && !_player.getUnitHealth().isDead());

    if(isGameOver()) {
        showGameOverMessage();
    } else {
        showGameWonMessage();
    }
}

bool Game::isGameOver() const {
    return _encounters.size() == 0;
}

void Game::navigateMap() {
    std::cout << std::endl << _worldMap << std::endl;
    std::cout << "Where would you like to go? (up/down/left/right): ";
}

void Game::processEncounter(Encounter &encounter) {
    do {
        encounter.playEncounterTurn(_player);
    } while(!encounter.isWon() && !_player.getUnitHealth().isDead());
}

void Game::showGameOverMessage() const {
    std::cout << std::endl << "This is the end of the road " << _player.getName() << "!" << std::endl;
    std::cout << "You have fought valiantly, but the enemies have overwhelmed you. Better luck next time!" << std::endl;
}

void Game::showGameWonMessage() const {
    std::cout << std::endl << "Well done " << _player.getName() << " you have succeeded in defeating all the enemies of the land.";
    std::cout << std::endl << "Go forth and know you are feared by your enemies!" << std::endl;
}
