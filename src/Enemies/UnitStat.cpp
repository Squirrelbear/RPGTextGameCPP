//
// Created by Peter on 27/12/2021.
//

#include "UnitStat.h"

UnitStat::UnitStat(const size_t statMax) {
    setStatMax(statMax);
}

void UnitStat::setStatMax(const size_t statMax, const bool changeCurrent) {
    _statMax = statMax;
    if(changeCurrent) {
        _statValue = _statMax;
    }
}

int UnitStat::getStatMax() const {
    return _statMax;
}

size_t UnitStat::decreaseStatBy(const size_t amount) {
    if(_statValue < amount) {
        size_t actualDamage = _statValue;
        _statValue = 0;
        return actualDamage;
    } else {
        _statValue -= amount;
        return amount;
    }
}

size_t UnitStat::increaseStatBy(const size_t amount) {
    _statValue += amount;
    if(_statValue > _statMax) {
        size_t difference = _statValue - _statMax;
        _statValue = _statMax;
        return difference;
    }
    return amount;
}

std::ostream &operator<<(std::ostream &out, const UnitStat &unitStat) {
    out << unitStat._statValue << " of " << unitStat._statMax;

    return out;
}

int UnitStat::getStatValue() const {
    return _statValue;
}

bool UnitStat::hasZeroStat() const {
    return _statValue == 0;
}
