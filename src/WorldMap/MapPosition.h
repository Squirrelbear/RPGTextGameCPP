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

    static MapPosition getDirectionOffsetFromString(const std::string direction) {
        if(direction == "up") return MOVE_OFFSET_UP;
        else if(direction == "down") return MOVE_OFFSET_DOWN;
        else if(direction == "left") return MOVE_OFFSET_LEFT;
        else if(direction == "right") return MOVE_OFFSET_RIGHT;
        else return {0,0};
    }
};

#endif //RPGTEXTCPP_MAPPOSITION_H
