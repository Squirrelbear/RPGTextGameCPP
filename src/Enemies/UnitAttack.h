//
// Created by Peter on 26/12/2021.
//

#ifndef RPGTEXTCPP_UNITATTACK_H
#define RPGTEXTCPP_UNITATTACK_H

#include <string>

class UnitAttack {
public:
    UnitAttack(const std::string& attackName, const int& damageMin, const int& damageMax,
               const float& criticalChance, const float& criticalDamageMultiplier, const size_t& manaCost);
    size_t getManaCost() const;
    std::string getName() const;
    int getRandomBaseDamage() const;
    bool isCriticalDamage() const;
    int getCriticalModifiedDamage(const int& baseDamage) const;

    friend std::ostream& operator<< (std::ostream& out, const UnitAttack& unitAttack);

private:
    int _baseDamageMin;
    int _baseDamageMax;
    float _criticalChance;
    float _criticalDamageMultiplier;
    std::string _attackName;
    size_t _manaCost;
};

#endif //RPGTEXTCPP_UNITATTACK_H
