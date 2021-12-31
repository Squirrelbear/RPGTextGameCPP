//
// Created by Peter on 26/12/2021.
//

#include <algorithm>
#include "Game.h"

Game::Game(const std::string& mapFileName, const std::string& assetsFileName, const std::string& playerName)
    : _assetDatabase(assetsFileName), _worldMap(mapFileName), _player(_assetDatabase.getRandomPlayerPrefab(playerName, {5,5})) {
    _worldMap.setOverlayAt(_player.getPlayerPosition(), _player.getMapOverlayChar());
    spawnEncounters(5, _worldMap.getMaxPosition());
    std::cout << "Welcome " << _player.getName() << "! You are represented by the @ symbol." << std::endl;
}

void Game::gameLoop() {
    do {
        navigateMap();
        int encounterID = getEncounterAt(_player.getPlayerPosition());
        if(encounterID == -1) {
            std::cerr << "ERROR!!! This should never happen..." << std::endl;
            continue;
        }
        processEncounter(_encounters.at(encounterID));
        if(_encounters.at(encounterID).isWon()) {
            _encounters.erase(_encounters.begin()+encounterID);
            _player.recoverStats();
        }
    } while(!allEncountersCleared() && !_player.getUnitHealth().isDead() && _player.hasUsableAbility());

    if(allEncountersCleared()) {
        showGameWonMessage();
    } else {
        if(!_player.getUnitHealth().isDead()) {
            std::cout << "You ran out of mana and the remaining enemy force wiped you out." << std::endl;
        }
        showGameOverMessage();
    }
}

void Game::spawnEncounters(const size_t count, const MapPosition& maxPosition) {
    for(int i = 0; i < count; i++) {
        MapPosition encounterPosition = MapPosition::getRandomPosition(maxPosition);
        while(!_worldMap.canMoveToPosition(encounterPosition)
                || getEncounterAt(encounterPosition) != -1
                || _player.getPlayerPosition() == encounterPosition) {
            encounterPosition = MapPosition::getRandomPosition(maxPosition);
        }
        std::vector<Enemy> enemyList = {_assetDatabase.getRandomEnemy()};
        Encounter newEncounter = Encounter(encounterPosition, enemyList);
        _encounters.push_back(newEncounter);
        _worldMap.setOverlayAt(encounterPosition, newEncounter.getEncounterChar());
    }
}

bool Game::allEncountersCleared() const {
    return _encounters.empty();
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
    return std::any_of(_encounters.begin(), _encounters.end(),
                       [&](const Encounter& encounter){
                                    return encounter.getMapPosition() == _player.getPlayerPosition();
                            });
}

int Game::getEncounterAt(const MapPosition &mapPosition) {
    int index = 0;
    for(auto& encounter : _encounters) {
        if(encounter.getMapPosition() == _player.getPlayerPosition()) {
            return index;
        }
        index++;
    }
    return -1;
}
