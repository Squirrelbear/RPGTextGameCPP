#include <iostream>
#include "Player/Player.h"
#include "WorldMap/WorldMap.h"

int main() {
    Player player = createPlayer();
    WorldMap worldMap("map.txt");

    std::cout << std::endl << worldMap << std::endl;
    std::cout << "Welcome " << player << "! You are represented by the @ symbol." << std::endl;
    std::cout << "Where would you like to go? (up/down/left/right): ";

    return 0;
}
