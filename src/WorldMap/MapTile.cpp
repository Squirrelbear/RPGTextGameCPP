//
// Created by Peter on 24/12/2021.
//

#include "MapTile.h"

MapTile::MapTile(const char tileChar, const bool isWalkable) {
    setTileChar(tileChar);
    setIsWalkable(isWalkable);
    _showOverlay = false;
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

void MapTile::setOverlay(const char overlayChar) {
    _overlayChar = overlayChar;
    _showOverlay = true;
}

void MapTile::hideOverlayChar() {
    _showOverlay = false;
}

bool MapTile::hasOverlay() const {
    return _showOverlay;
}

char MapTile::getOverlayChar() const {
    return _overlayChar;
}

std::ostream& operator<< (std::ostream& out, const MapTile& tile) {
    out << (tile._showOverlay ? tile._overlayChar : tile._tileChar);

    return out;
}