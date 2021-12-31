//
// Created by Peter on 24/12/2021.
//

#include "WorldMap.h"
#include <fstream>

WorldMap::WorldMap(const std::string& fileName) {
    loadMap(fileName);
}

void WorldMap::loadMap(const std::string& fileName) {
    _mapFileName = fileName;
    reloadMap();
}

void WorldMap::reloadMap() {
    _map.clear();
    std::ifstream mapFile(_mapFileName);
    if(!mapFile.is_open()) {
        std::cerr << "Failed to open map file using default instead: " << _mapFileName << std::endl;
        mapFile.close();
        loadDefaultMap();
        return;
    }
    int height, width;
    mapFile >> height >> width;
    if(mapFile.fail()) {
        std::cerr << "Failed to read valid height and width from map file: " << _mapFileName << std::endl;
        mapFile.close();
        loadDefaultMap();
        return;
    }

    char mapBaseTile;
    for(int y = 0; y < height; y++) {
        std::vector<MapTile> tileRow;
        tileRow.reserve(width);
        for(int x = 0; x < width; x++) {
            mapFile >> mapBaseTile;
            if(mapFile.fail()) {
                std::cerr << "Failed to read valid map tile (" << x << ", " << y << ")." << std::endl;
                return;
            }
            tileRow.emplace_back(MapTile(mapBaseTile, mapBaseTile == '.'));
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

bool WorldMap::canMoveToPosition(const MapPosition &mapPosition) {
    if(mapPosition.x < 0 || mapPosition.y < 0 || mapPosition.y >= _map.size()
            || mapPosition.x >= _map.at(0).size()) {
        return false;
    }

    return _map.at(mapPosition.y).at(mapPosition.x).isWalkable();
}

void WorldMap::hideOverlayAt(const MapPosition &mapPosition) {
    _map.at(mapPosition.y).at(mapPosition.x).hideOverlayChar();
}

void WorldMap::setOverlayAt(const MapPosition &mapPosition, const char overlayChar) {
    _map.at(mapPosition.y).at(mapPosition.x).setOverlay(overlayChar);
}

char WorldMap::getOverlayAt(const MapPosition &mapPosition) {
    return _map.at(mapPosition.y).at(mapPosition.x).getOverlayChar();
}

MapPosition WorldMap::getMaxPosition() const {
    if(_map.empty() || _map.at(0).empty()) {
        return {0,0};
    }

    return {(int)_map.at(0).size(), (int)_map.size()};
}

void WorldMap::loadDefaultMap() {
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
