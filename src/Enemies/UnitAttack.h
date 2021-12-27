//
// Created by Peter on 26/12/2021.
//

#ifndef RPGTEXTCPP_UNITATTACK_H
#define RPGTEXTCPP_UNITATTACK_H

#include <string>

class UnitAttack {
public:
    size_t getManaCost() const;

private:
    int _baseDamageMin;
    int _baseDamageMax;
    float _criticalChance;
    float _criticalDamageMultiplier;
    std::string _attackName;
    size_t _manaCost;
};

#endif //RPGTEXTCPP_UNITATTACK_H
