#include <iostream>
#include "Player.h"

int main() {
    Player player = createPlayer();

    std::cout << "Welcome " << player << "!" << std::endl;
    return 0;
}
