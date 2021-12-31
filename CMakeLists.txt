cmake_minimum_required(VERSION 3.17)
project(RPGTextCPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(RPGTextCPP src/main.cpp src/Player/Player.cpp src/Player/Player.h src/WorldMap/WorldMap.cpp src/WorldMap/WorldMap.h src/WorldMap/MapTile.cpp src/WorldMap/MapTile.h src/Enemies/Encounter.cpp src/Enemies/Encounter.h src/Enemies/Enemy.cpp src/Enemies/Enemy.h src/Enemies/UnitHealth.cpp src/Enemies/UnitHealth.h src/Enemies/UnitAttack.cpp src/Enemies/UnitAttack.h src/Enemies/CombatUnit.cpp src/Enemies/CombatUnit.h src/Game.cpp src/Game.h src/WorldMap/MapPosition.h src/Enemies/UnitMana.cpp src/Enemies/UnitMana.h src/Enemies/UnitStat.cpp src/Enemies/UnitStat.h src/AssetDatabase/AssetDatabase.cpp src/AssetDatabase/AssetDatabase.h src/AssetDatabase/Prefab.cpp src/AssetDatabase/Prefab.h src/Utilities/StringUtility.h)

# Solution for copying all files with extension: https://stackoverflow.com/questions/24311402/copy-all-files-with-given-extension-to-output-directory-using-cmake
file(GLOB GAME_APP_DATA "appdata/*.txt")
file(COPY ${GAME_APP_DATA} DESTINATION ${CMAKE_BINARY_DIR})