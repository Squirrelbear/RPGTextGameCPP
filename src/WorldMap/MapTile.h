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

    // Set the base tile type
    void setTileChar(const char tileChar);
    // Get the base tile type
    char getTileChar() const;

    // Sets if the tile is walkable by AI and player.
    void setIsWalkable(const bool isWalkable);
    // Gets if the tile is walkable by AI and player.
    bool isWalkable() const;

    /* Sets the character to overlay on this tile and overrides the base tile.
        Calling hideOverlayChar() will hide it again.
     */
    void setOverlay(const char overlayChar);
    // Hides any active overlay character returning the display to be the base tile.
    void hideOverlayChar();
    // Returns true when the base tile is hidden by an overlay character.
    bool hasOverlay() const;
    // Gets the character that is currently overlaying the base tile of this MapTile.
    char getOverlayChar() const;

    // Prints out the current tile as either the base tile or overlaid tile if it has an overlay.
    friend std::ostream& operator<< (std::ostream& out, const MapTile& tile);

private:
    char _tileChar;
    bool _isWalkable;
    char _overlayChar;
    bool _showOverlay;
};


#endif //RPGTEXTCPP_MAPTILE_H
