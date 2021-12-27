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
    std::optional<UnitAttack> getUnitAttack(const size_t attackID) const;
    std::optional<UnitAttack> getRandomUnitAttack() const;
    size_t getAttackCount() const;
    char getMapOverlayChar() const;

    friend std::ostream& operator<< (std::ostream& out, const CombatUnit& combatUnit);

    virtual std::optional<UnitAttack> chooseAttack() = 0;

private:
    char _mapOverlayChar;
    std::string _unitName;
    UnitHealth _unitHealth;
    UnitMana _unitMana;
    std::vector<UnitAttack> _attackTypes;
};


#endif //RPGTEXTCPP_COMBATUNIT_H
