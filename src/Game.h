//
// Created by Peter on 26/12/2021.
//

#ifndef RPGTEXTCPP_GAME_H
#define RPGTEXTCPP_GAME_H


#include <vector>
#include "Enemies/Encounter.h"
#include "Player/Player.h"
#include "WorldMap/WorldMap.h"

class Game {
public:
    Game(const std::string& mapFileName, const Player& player);
    void gameLoop();

private:
    std::vector<Encounter> _encounters;
    Player _player;
    WorldMap _worldMap;

    void spawnEncounters(const size_t count, const MapPosition& maxPosition);
    bool isGameOver() const;
    void navigateMap();
    void processEncounter(Encounter& encounter);
    void showGameOverMessage() const;
    void showGameWonMessage() const;
    bool movePlayer(const MapPosition& moveOffset);
    bool isPlayerAtEncounter() const;
    int getEncounterAt(const MapPosition& mapPosition);
};


#endif //RPGTEXTCPP_GAME_H
