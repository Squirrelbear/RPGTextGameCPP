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
    _map.clear();
    for(int y = 0; y < 15; y++) {
        std::vector<MapTile> tileRow;
        tileRow.reserve(15);
        for(int x = 0; x < 15; x++) {
            tileRow.emplace_back();
        }
        _map.push_back(tileRow);
    }
}

std::ostream& operator<< (std::ostream& out, const WorldMap& worldMap) {
    for(const auto & row : worldMap._map) {
        for(auto tile : row) {
            out << tile << " ";
        }
        out << std::endl;
    }

    return out;
}