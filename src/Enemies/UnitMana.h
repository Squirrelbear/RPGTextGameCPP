//
// Created by Peter on 27/12/2021.
//

#ifndef RPGTEXTCPP_UNITMANA_H
#define RPGTEXTCPP_UNITMANA_H

#include <iostream>
#include "UnitStat.h"

class UnitMana : public UnitStat {
public:
    explicit UnitMana(const size_t manaMax) : UnitStat(manaMax) {}
};


#endif //RPGTEXTCPP_UNITMANA_H
