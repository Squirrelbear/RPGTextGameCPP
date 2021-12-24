//
// Created by Peter on 24/12/2021.
//

#include "WorldMap.h"

WorldMap::WorldMap(const std::string fileName) {
    loadMap(fileName);
}

void WorldMap::loadMap(const std::string fileName) {
    _mapFileName = fileName;
    reloadMap();
}

void WorldMap::reloadMap() {

}