//
// Created by Peter on 27/12/2021.
//

#ifndef RPGTEXTCPP_MAPPOSITION_H
#define RPGTEXTCPP_MAPPOSITION_H

#include <string>

#define MOVE_OFFSET_UP {0,-1}
#define MOVE_OFFSET_DOWN {0,1}
#define MOVE_OFFSET_LEFT {-1,0}
#define MOVE_OFFSET_RIGHT {1,0}

struct MapPosition {
    int x;
    int y;

    friend MapPosition operator+(const MapPosition &lhs, const MapPosition &rhs) {
        MapPosition result{lhs.x+rhs.x, lhs.y+rhs.y};
        return result;
    }

    friend bool operator==(const MapPosition &lhs, const MapPosition &rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }

    friend bool operator!=(const MapPosition &lhs, const MapPosition &rhs) {
        return !(lhs == rhs);
    }

    /*
     * Expects a string in lower case matching any of "up', "down", "left" or "right".
     * Returns a MapPosition object matching the associated direction unit vector.
     * If no match was found {0,0} is returned.
     */
    static MapPosition getDirectionOffsetFromString(const std::string& direction) {
        if(direction == "up") return MOVE_OFFSET_UP;
        else if(direction == "down") return MOVE_OFFSET_DOWN;
        else if(direction == "left") return MOVE_OFFSET_LEFT;
        else if(direction == "right") return MOVE_OFFSET_RIGHT;
        else return {0,0};
    }

    // Returns a random position from 0 to maxPosition for each axis.
    static MapPosition getRandomPosition(const MapPosition& maxPosition) {
        return {rand() % maxPosition.x, rand() % maxPosition.y };
    }
};

#endif //RPGTEXTCPP_MAPPOSITION_H
