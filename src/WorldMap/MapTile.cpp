//
// Created by Peter on 24/12/2021.
//

#include "MapTile.h"

MapTile::MapTile(const char tileChar, const bool isWalkable) {
    setTileChar(tileChar);
    setIsWalkable(isWalkable);
}

void MapTile::setTileChar(const char tileChar) {
    _tileChar = tileChar;
}

char MapTile::getTileChar() const {
    return _tileChar;
}

void MapTile::setIsWalkable(const bool isWalkable) {
    _isWalkable = isWalkable;
}

bool MapTile::isWalkable() const {
    return _isWalkable;
}

std::ostream& operator<< (std::ostream& out, const MapTile& tile) {
    out << tile._tileChar;

    return out;
}