cmake_minimum_required(VERSION 3.17)
project(RPGTextCPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(RPGTextCPP src/main.cpp src/Player/Player.cpp src/Player/Player.h src/WorldMap/WorldMap.cpp src/WorldMap/WorldMap.h src/WorldMap/MapTile.cpp src/WorldMap/MapTile.h)