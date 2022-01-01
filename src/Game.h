//
// Created by Peter on 26/12/2021.
//

#ifndef RPGTEXTCPP_GAME_H
#define RPGTEXTCPP_GAME_H

#include <vector>
#include "Enemies/Encounter.h"
#include "Player/Player.h"
#include "WorldMap/WorldMap.h"
#include "AssetDatabase/AssetDatabase.h"

// Entry point for the game. Manages the Map navigation and encounters.
class Game {
public:
    /*
     * Initialises all content required for the game.
     *
     * @param assetsFileName The file containing all properties to be used in the game.
     * @param playerName The chosen name for the player.
     */
    Game(const std::string& assetsFileName, const std::string& playerName);
    // Loops until the game is over swapping between navigating the map and managing encounters.
    void gameLoop();

private:
    // All the prefab data used to generate encounters and the player's attacks.
    AssetDatabase _assetDatabase;
    // The remaining encounters waiting for the player to defeat them.
    std::vector<Encounter> _encounters;
    // The player object that is seeking to defeat encounters.
    Player _player;
    // The world map that may be traversed by the player to engage with the encounters.
    WorldMap _worldMap;

    // Spawns count number of encounters randomly across the map based on the maxPosition specified.
    void spawnEncounters(const size_t count, const MapPosition& maxPosition);
    // Returns true if there are no more encounters remaining.
    bool allEncountersCleared() const;
    // Loops showing the map and asking the player to travel up/down/left/right until they reach an encounter.
    void navigateMap();
    // Loops while an encounter is in progress until either all enemies are dead or the player is dead.
    void processEncounter(Encounter& encounter);
    // Shows a message for when the player has died and lost the game overall.
    void showGameOverMessage() const;
    // Shows a message for when the player has defeated all encounters successfully.
    void showGameWonMessage() const;
    // Moves the player if possible by modifying the player's position and the overlays on the world map. Returns false if the move was not valid.
    bool movePlayer(const MapPosition& moveOffset);
    // Returns true when the player's position matches one of the encounters defined in the encounter list.
    bool isPlayerAtEncounter() const;
    // Gets the index in the encounter list of the encounter at a specified position. Returns -1 if there is none.
    int getEncounterAt(const MapPosition& mapPosition);
};

/*
 * Entry point for the game. Starts by asking the player to enter their name and then creates a game.
 * Once the game has ended the player is asked if they wish to play again.
 *
 * @param assetFileName The file defining all the properties for the game.
 *                      See AssetDatabase.h for specifications on how the file should be laid out.
 */
void playGame(const std::string& assetFileName);


#endif //RPGTEXTCPP_GAME_H
