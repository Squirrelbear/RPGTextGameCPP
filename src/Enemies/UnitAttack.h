//
// Created by Peter on 26/12/2021.
//

#ifndef RPGTEXTCPP_UNITATTACK_H
#define RPGTEXTCPP_UNITATTACK_H

#include <string>

class UnitAttack {
public:

private:
    int baseDamageMin;
    int baseDamageMax;
    float criticalChance;
    float criticalDamageMultiplier;
    std::string attackName;
    int manaCost;
};

#endif //RPGTEXTCPP_UNITATTACK_H
