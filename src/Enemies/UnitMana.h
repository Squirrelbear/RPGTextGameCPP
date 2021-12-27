//
// Created by Peter on 27/12/2021.
//

#ifndef RPGTEXTCPP_UNITMANA_H
#define RPGTEXTCPP_UNITMANA_H

#include <iostream>
#include "UnitAttack.h"
#include "UnitStat.h"

class UnitMana : public UnitStat {
public:
    explicit UnitMana(const size_t manaMax) : UnitStat(manaMax) {}

    /*
     * Returns true when there is equal or more mana required for the attack.
     */
    bool canCastWithMana(const UnitAttack& unitAttack);
    /*
     * Uses decreaseStatBy to reduce the mana for the attack.
     */
    void consumeManaForAttack(const UnitAttack& unitAttack);
};


#endif //RPGTEXTCPP_UNITMANA_H
