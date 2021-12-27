//
// Created by Peter on 26/12/2021.
//

#include "UnitHealth.h"

bool UnitHealth::isDead() const {
    return getStatValue() == 0;
}
