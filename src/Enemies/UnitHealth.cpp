//
// Created by Peter on 26/12/2021.
//

#include "UnitHealth.h"

UnitHealth::UnitHealth(const size_t healthMax) {
    setHealthMax(healthMax);
}

void UnitHealth::setHealthMax(const size_t healthMax, const bool changeCurrent) {
    _healthMax = healthMax;
    if(changeCurrent) {
        _healthValue = _healthMax;
    }
}

int UnitHealth::getHealthMax() const {
    return _healthMax;
}

size_t UnitHealth::decreaseHealthBy(const size_t amount) {
    if(_healthValue < amount) {
        size_t actualDamage = _healthValue;
        _healthValue = 0;
        return actualDamage;
    } else {
        _healthValue -= amount;
        return amount;
    }
}

size_t UnitHealth::increaseHealthBy(const size_t amount) {
    _healthValue += amount;
    if(_healthValue > _healthMax) {
        size_t difference = _healthValue - _healthMax;
        _healthValue = _healthMax;
        return difference;
    }
    return amount;
}

bool UnitHealth::isDead() const {
    return _healthValue == 0;
}

std::ostream &operator<<(std::ostream &out, const UnitHealth &unitHealth) {
    out << unitHealth._healthValue << " of " << unitHealth._healthMax;

    return out;
}

