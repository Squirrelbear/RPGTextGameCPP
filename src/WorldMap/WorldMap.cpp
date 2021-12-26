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
        for(int x = 0; x < 15; x++) {
            tileRow.push_back(MapTile());
        }
        _map.push_back(tileRow);
    }
}

std::ostream& operator<< (std::ostream& out, const WorldMap& worldMap) {
    for(int y = 0; y < worldMap._map.size(); y++) {
        for(int x = 0; x < worldMap._map.at(y).size(); x++) {
            out << worldMap._map.at(y).at(x) << " ";
        }
#ifdef WORLD_MAP_SHOW_NUMBERS
        out << " |" << (y+1) << std::endl;
#else
        out << std::endl;
#endif
    }
#ifdef WORLD_MAP_SHOW_NUMBERS
    for(int x = 0; x < worldMap._map.at(0).size(); x++) {
        out << "- ";
    }
    out << std::endl;
    for(int x = 0; x < worldMap._map.at(0).size(); x++) {
        out << (x+1) << " ";
    }
    out << std::endl;
#endif

    return out;
}