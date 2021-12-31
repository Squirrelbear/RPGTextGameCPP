#include <iostream>
#include <ctime>
#include "Player/Player.h"
#include "Game.h"

int main() {
    srand(time(nullptr));

    std::string playAgainInput;
    std::string playerName = choosePlayerName();

    do {
        Game game("TODO", "assetdata.txt", playerName);
        game.gameLoop();

        std::cout << "Play Again (Y/N): ";
        std::cin >> playAgainInput;
    } while(playAgainInput == "Y");

    std::cout << std::endl << std::endl << "Thank you for playing! See you next time!" << std::endl;

    return 0;
}
