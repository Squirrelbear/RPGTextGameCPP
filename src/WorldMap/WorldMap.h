//
// Created by Peter on 24/12/2021.
//

#ifndef RPGTEXTCPP_WORLDMAP_H
#define RPGTEXTCPP_WORLDMAP_H

#include <iostream>
#include <vector>
#include "MapTile.h"
#include "MapPosition.h"

/*
 * Represents a map with a 2D grid of MapTile objects.
 *
 * World map data is defined in a file containing only the world map data.
 * The file format is as follows.
 * First line (both defined as integers): [map height] [map width]
 * Each subsequent line should be space separated characters with a separate line for each height.
 * Each line should contain width number of characters.
 *
 * Example:
    15 15
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
    # # # # # # # # # # # # # # #
 */
class WorldMap {
public:
    // Initialises the WorldMap by loading from the specified file name.
    explicit WorldMap(const std::string& fileName);

    // Removes the current map and loads the map using the specified file name.
    void loadMap(const std::string& fileName);
    // Removes the current map and replaces with a reload from the last loaded file.
    void reloadMap();

    // Returns true if the position is within the map bounds and is walkable.
    bool canMoveToPosition(const MapPosition& mapPosition);
    // Hides any overlay at the specified map position.
    void hideOverlayAt(const MapPosition& mapPosition);
    // Shows the specified overlay at the specified map position.
    void setOverlayAt(const MapPosition& mapPosition, const char overlayChar);
    // Gets the current overlay at a specified map position.
    char getOverlayAt(const MapPosition& mapPosition);
    // Gets the maximum bounds of the map.
    MapPosition getMaxPosition() const;

    // Outputs each row on an individual line for the full contents of the map.
    friend std::ostream& operator<< (std::ostream& out, const WorldMap& worldMap);

private:
    // 2D array containing the map
    std::vector<std::vector<MapTile>> _map;
    // The file used for loading/reloading the map
    std::string _mapFileName;

    // A fallback map that has all cells walkable. Only used if map fails to load.
    void loadDefaultMap();
};


#endif //RPGTEXTCPP_WORLDMAP_H
