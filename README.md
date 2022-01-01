# RPG Text Game C++ Edition

Designed and developed by Peter Mitchell

A C++ version of my RPG Text Game that was also written in Java: ([Java version Github Link](https://github.com/Squirrelbear/RPGTextGame))
 
The game has the player start by choosing their name. Then the game alternates between navigating a map and battling turn-based encounters. Map navigation is done by entering up/down/left/right to move the player's character. When the player reaches a position for an encounter the encounter begins and continues until either all enemies are defeated or the player is defeated. Attacks are selected by entering the number associated with the attack and are defaulted to be used if there is only one option based on remaining mana. At the end of each encounter if the player is still alive they recover mana and health.

A CMake file is provided to compile the project and will copy the contents of the appdata folder into the build directory when it is loaded. These assets are required to define configuration of the player's stats, enemy stats, attacks, enemy names, and any map files that are associated with the game.

## Configuration File (assetdata.txt)

The assetDatabaseFile passed to the constructor must have each line of the file as a separate definition.
 Each definition starts with a prefab type and then a specific ordered list of attributes required for each.
 The following identifies the format for each of these.

 ### PLAYER [initial max health] [initial max mana] [attack ids (1+)]
 * Initial max health and initial max mana should be positive integers.
 * Attack ids should match the attack ids for attack type prefabs.
 * Example: PLAYER 100 100 0 1 2 3 4

 ### ENEMYNAME [enemy type] [name]
 * Enemy type must appear as a single word with no spaces.
 * Name can have any amount of spacing as everything after the enemy type is considered the name.
 * Example: ENEMYNAME Orc Thrall

 ### ENEMY [enemy type] [map overlay character] [initial max health] [initial max mana] [attack ids (1+)]
 * Enemy type must appear as a single word with no spaces.
 * Map overlay character must be a single character.
 * Initial max health and initial max mana should be positive integers.
 * Attack ids should match the attack ids for attack type prefabs.
 * Example: ENEMY Orc O 100 100 5 6 7

 ### ATTACK [attack id] [damage min] [damage max] [critical chance] [critical damage multiplier] [mana cost] [attack name]
 * Attack id must be a unique id for each attack.
 * Damage min and damage max must be integer values where min is less than or equal to max.
 * Critical chance can be a float and should be written as 60.5 for 60.5%
 * Critical damage multiplier is a float and can be any valid float value.
 * Mana cost must be a positive integer.
 * Attack name can have any length with as many spaces as desired everything after mana cost is considered the name.
 * Example: ATTACK 0 5 10 30 1.5 5 Magic Missile

 ### MAP [map file name]
 * File name can be any valid file name in the application directory containing map data.
 * Example: MAP map.txt

## Map Files

World map data is defined in a file containing only the world map data. The file format is as follows.
* First line (both defined as integers): [map height] [map width]
* Each subsequent line should be space separated characters with a separate line for each height.
* Each line should contain width number of characters.
* Example:
    '''15 15
    # # # # # # # # # # # # # # #
    # . . . . . . . . . . . . . #
    # . . . . . . . . . . . . . #
    # . . . . . . . . . . . . . #
    # . . . . . . . . . . . . . #
    # . . . . . . . . . . . . . #
    # . . . . . . . . . . . . . #
    # . . . . . . . . . . . . . #
    # . . . . . . . . . . . . . #
    # . . . . . . . . . . . . . #
    # . . . . . . . . . . . . . #
    # . . . . . . . . . . . . . #
    # . . . . . . . . . . . . . #
    # . . . . . . . . . . . . . #
    # # # # # # # # # # # # # # #'''