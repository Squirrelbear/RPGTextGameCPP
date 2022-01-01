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

/*
 * A pure virtual class intended to be inherited by specific types of combat unit.
 * Any class that inherits this class should override the chooseAttack() method
 * by providing a definition that controls how an attack is to be selected from
 * those available.
 */
class CombatUnit {
public:
    /*
     * Initialises a combat unit with the required properties.
     * 
     * @param unitName The name of this combat unit.
     * @param mapOverlayChar The character used to represent this combat unit on the map.
     * @param initialMaxHealth The initial health maximum for this unit.
     * @param initialMaxMana The initial mana maximum for this unit.
     * @param attackTypes One or more attacks that this unit can use in combat.
     */
    CombatUnit(const std::string& unitName, const char mapOverlayChar, const size_t initialMaxHealth,
               const size_t initialMaxMana, const std::vector<UnitAttack>& attackTypes);
    // Gets the combat unit's name.
    std::string getName() const;
    // Gets a reference to the combat unit's health stat.
    UnitHealth& getUnitHealth();
    // Gets a reference to the combat unit's mana stat.
    UnitMana& getUnitMana();
    // Returns an attack matching the specified ID or std::nullopt if out of range.
    std::optional<UnitAttack> getUnitAttack(const size_t attackID) const;
    // Gets all the usable attacks and returns std::nullopt if none are usable, or a random usable one.
    std::optional<UnitAttack> getRandomUnitAttack();
    // Gets the number of attacks available to this combat unit.
    size_t getAttackCount() const;
    // Gets the character to be displayed on the map for this combat unit.
    char getMapOverlayChar() const;
    /*
     * Consumes mana for the specified attack and uses this combat unit as the attack to apply
     * the attack toward the attackTarget including output of the result.
     */
    void performAttackOn(const UnitAttack& attack, CombatUnit &attackTarget);
    // Returns true if the combat unit has at least one usable ability given their current mana.
    bool hasUsableAbility();

    // Outputs the object in the form: {name} has {healthValue} of {healthMax} HP and {manaValue} of {manaMax} Mana.
    friend std::ostream& operator<< (std::ostream& out, const CombatUnit& combatUnit);

    // Pure virtual method used to select an attack by classes that inherit this class.
    virtual std::optional<UnitAttack> chooseAttack() = 0;

protected:
    // Gets a list of all usable attack ids based on current mana.
    std::vector<int> getUsableAttacks();

private:
    // The character used to represent this combat unit on the map.
    char _mapOverlayChar;
    // The name of this combat unit.
    std::string _unitName;
    // The health stat of this combat unit.
    UnitHealth _unitHealth;
    // The mana stat of this combat unit.
    UnitMana _unitMana;
    // The list of attacks available to the combat unit.
    std::vector<UnitAttack> _attackTypes;

    // Returns true when there is equal or more mana required for the attack.
    bool canCastWithMana(const UnitAttack& attackType);
    // Uses decreaseStatBy to reduce the mana for the attack.
    void consumeManaForAttack(const UnitAttack& attackType);
};

#endif //RPGTEXTCPP_COMBATUNIT_H
