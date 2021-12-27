//
// Created by Peter on 26/12/2021.
//

#ifndef RPGTEXTCPP_UNITHEALTH_H
#define RPGTEXTCPP_UNITHEALTH_H

#include <iostream>
#include "UnitStat.h"

class UnitHealth : public UnitStat {
public:
    explicit UnitHealth(const size_t healthMax) : UnitStat(healthMax) {}
    /*
     * Returns true when health has reached 0.
     */
    bool isDead() const;
};


#endif //RPGTEXTCPP_UNITHEALTH_H
