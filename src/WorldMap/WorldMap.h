//
// Created by Peter on 24/12/2021.
//

#ifndef RPGTEXTCPP_WORLDMAP_H
#define RPGTEXTCPP_WORLDMAP_H

#include <iostream>
#include <vector>
#include "MapTile.h"
#include "MapPosition.h"

//#define WORLD_MAP_SHOW_NUMBERS

// Represents a map with a 2D grid of MapTile objects.
class WorldMap {
public:
    // Initialises the WorldMap by loading from the specified file name.
    WorldMap(const std::string fileName);

    // Removes the current map and loads the map using the specified file name.
    void loadMap(const std::string fileName);
    // Removes the current map and replaces with a reload from the last loaded file.
    void reloadMap();

    bool canMoveToPosition(const MapPosition& mapPosition);
    void hideOverlayAt(const MapPosition& mapPosition);
    void setOverlayAt(const MapPosition& mapPosition, const char overlayChar);
    char getOverlayAt(const MapPosition& mapPosition);

    friend std::ostream& operator<< (std::ostream& out, const WorldMap& worldMap);

private:
    // 2D array containing the map
    std::vector<std::vector<MapTile>> _map;
    // The file used for loading/reloading the map
    std::string _mapFileName;
};


#endif //RPGTEXTCPP_WORLDMAP_H
