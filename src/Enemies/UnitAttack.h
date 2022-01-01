//
// Created by Peter on 26/12/2021.
//

#ifndef RPGTEXTCPP_UNITATTACK_H
#define RPGTEXTCPP_UNITATTACK_H

#include <string>

// Defines an attack with methods to generate the attack's random properties.
class UnitAttack {
public:
    // Empty constructor required for map to use []
    UnitAttack() {}
    /*
     * Defines the properties of a UnitAttack.
     *
     * @param attackName The name of the attack.
     * @param damageMin The minimum damage an attack can deal. This value should be lower than or equal to the max.
     * @param damageMax The maximum damage an attack can deal (before critical multiplication).
     * @param criticalChance The chance for an attack to be a critical strike E.g. 60.5 is 60.5% chance.
     * @param criticalDamageMultiplier The multiplier used when an attack is randomised to be a critical strike.
     * @param manaCost The mana cost to use the attack.
     */
    UnitAttack(const std::string& attackName, const int& damageMin, const int& damageMax,
               const float& criticalChance, const float& criticalDamageMultiplier, const size_t& manaCost);
    // Gets the cost to use the attack.
    size_t getManaCost() const;
    // Gets the name of the attack.
    std::string getName() const;
    // Gets a random number (inclusive) between the damage min and damage max.
    int getRandomBaseDamage() const;
    // Returns true if the attack is a critical strike based on the critical chance.
    bool isCriticalDamage() const;
    // Returns the modified damage after applying the critical damage modifier.
    int getCriticalModifiedDamage(const int& baseDamage) const;

    /* Outputs in the form:
    {attackName} ({damageMin} to {damageMax} damage) {criticalChance}% chance of x{criticalDamageMultiplier} Mana Cost: {manaCost}
     */
    friend std::ostream& operator<< (std::ostream& out, const UnitAttack& unitAttack);

private:
    // The minimum damage an attack can deal. This value should be lower than or equal to the max.
    int _baseDamageMin;
    // The maximum damage an attack can deal (before critical multiplication).
    int _baseDamageMax;
    // The chance for an attack to be a critical strike E.g. 60.5 is 60.5% chance.
    float _criticalChance;
    // The multiplier used when an attack is randomised to be a critical strike.
    float _criticalDamageMultiplier;
    // The name of the attack.
    std::string _attackName;
    // The mana cost to use the attack.
    size_t _manaCost;
};

#endif //RPGTEXTCPP_UNITATTACK_H
