//
// Created by Peter on 26/12/2021.
//

#ifndef RPGTEXTCPP_COMBATUNIT_H
#define RPGTEXTCPP_COMBATUNIT_H


#include <vector>
#include <optional>
#include "UnitHealth.h"
#include "UnitAttack.h"
#include "UnitMana.h"

class CombatUnit {
public:
    CombatUnit(const std::string unitName, const char mapOverlayChar, const size_t initialMaxHealth);
    std::string getName() const;
    void setName(const std::string unitName);
    UnitHealth& getUnitHealth();
    UnitMana& getUnitMana();
    std::optional<UnitAttack> getUnitAttack(const size_t attackID) const;
    std::optional<UnitAttack> getRandomUnitAttack() const;
    size_t getAttackCount() const;
    char getMapOverlayChar() const;
    void performAttackOn(const UnitAttack& attack, CombatUnit &attackTarget);

    friend std::ostream& operator<< (std::ostream& out, const CombatUnit& combatUnit);

    virtual std::optional<UnitAttack> chooseAttack() = 0;

private:
    char _mapOverlayChar;
    std::string _unitName;
    UnitHealth _unitHealth;
    UnitMana _unitMana;
    std::vector<UnitAttack> _attackTypes;

    /*
     * Returns true when there is equal or more mana required for the attack.
     */
    bool canCastWithMana(const UnitAttack& attackType);
    /*
     * Uses decreaseStatBy to reduce the mana for the attack.
     */
    void consumeManaForAttack(const UnitAttack& attackType);
};


#endif //RPGTEXTCPP_COMBATUNIT_H
