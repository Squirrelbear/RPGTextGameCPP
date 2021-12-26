//
// Created by Peter on 26/12/2021.
//

#ifndef RPGTEXTCPP_COMBATUNIT_H
#define RPGTEXTCPP_COMBATUNIT_H


#include <vector>
#include "UnitHealth.h"
#include "UnitAttack.h"

class CombatUnit {
public:
    CombatUnit();
    UnitHealth& getUnitHealth();
    UnitAttack getUnitAttack(const size_t attackID) const;
    UnitAttack getRandomUnitAttack() const;
    size_t getAttackCount() const;

    virtual UnitAttack chooseAttack() = 0;

private:
    UnitHealth _unitHealth;
    std::vector<UnitAttack> _attackTypes;
};


#endif //RPGTEXTCPP_COMBATUNIT_H
