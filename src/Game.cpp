//
// Created by Peter on 26/12/2021.
//

#include <algorithm>
#include "Game.h"

Game::Game(const std::string mapFileName, const Player& player)
    : _worldMap(mapFileName), _player(player) {
    _worldMap.setOverlayAt(_player.getPlayerPosition(), _player.getMapOverlayChar());
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
    std::string input;
    do {
        std::cout << std::endl << _worldMap << std::endl;
        std::cout << "Where would you like to go? (up/down/left/right): ";
        std::getline(std::cin, input);
        std::transform(input.begin(), input.end(), input.begin(),
                                [](unsigned char c){ return std::tolower(c); });
        MapPosition offset = MapPosition::getDirectionOffsetFromString(input);
        movePlayer(offset);
    } while(!isPlayerAtEncounter());
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

bool Game::movePlayer(const MapPosition &moveOffset) {
    MapPosition newPosition = moveOffset + _player.getPlayerPosition();
    if(!_worldMap.canMoveToPosition(newPosition)) {
        std::cout << "You can't move there! Try a different direction!" << std::endl;
        return false;
    }

    _worldMap.hideOverlayAt(_player.getPlayerPosition());
    _player.setPlayerPosition(newPosition);
    _worldMap.setOverlayAt(newPosition, _player.getMapOverlayChar());
    return true;
}

bool Game::isPlayerAtEncounter() const {
    for(auto& encounter : _encounters) {
        if(encounter.getMapPosition() == _player.getPlayerPosition()) {
            return true;
        }
    }
    return false;
}
