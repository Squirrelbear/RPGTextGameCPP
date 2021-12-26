//
// Created by Peter on 26/12/2021.
//

#include "Game.h"

Game::Game(const std::string mapFileName)
    : _worldMap(mapFileName) {

}

void Game::gameLoop() {

}

bool Game::isGameOver() const {
    return _encounters.size() == 0;
}
