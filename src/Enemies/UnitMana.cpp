//
// Created by Peter on 27/12/2021.
//

#include "UnitMana.h"

bool UnitMana::canCastWithMana(const UnitAttack &unitAttack) {
    return getStatValue() >= unitAttack.getManaCost();
}

void UnitMana::consumeManaForAttack(const UnitAttack &unitAttack) {
    decreaseStatBy(unitAttack.getManaCost());
}