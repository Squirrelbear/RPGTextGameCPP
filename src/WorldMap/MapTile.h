//
// Created by Peter on 24/12/2021.
//

#ifndef RPGTEXTCPP_MAPTILE_H
#define RPGTEXTCPP_MAPTILE_H

#include <iostream>

// Represents a generic map tile that can show as a character on the world map.
class MapTile {
public:
    // Defaults the map tile to a . empty character that can be walked
    MapTile() : MapTile('.', true) {}
    MapTile(const char tileChar, const bool isWalkable);

    void setTileChar(const char tileChar);
    char getTileChar() const;

    void setIsWalkable(const bool isWalkable);
    bool isWalkable() const;

    void setOverlay(const char overlayChar);


    friend std::ostream& operator<< (std::ostream& out, const MapTile& tile);

private:
    char _tileChar;
    bool _isWalkable;
    char _overlayChar;
    bool _hideOverlay;
};


#endif //RPGTEXTCPP_MAPTILE_H
