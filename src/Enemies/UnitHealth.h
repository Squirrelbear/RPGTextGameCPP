//
// Created by Peter on 26/12/2021.
//

#ifndef RPGTEXTCPP_UNITHEALTH_H
#define RPGTEXTCPP_UNITHEALTH_H

#include <iostream>

class UnitHealth {
public:
    UnitHealth(const size_t healthMax);
    /*
     * Sets the maximum health AND current health to healthMax.
     */
    void setHealthMax(const size_t healthMax, const bool changeCurrent = true);
    int getHealthMax() const;
    /*
     * Decreases health value by up to amount. Will not reduce below 0.
     * Returns the actual damage dealt, which will vary when overkilling.
     */
    size_t decreaseHealthBy(const size_t amount);
    /*
     * Increases health value by up to amount. Will not increase above max health.
     * Returns the actual healing applied, which will vary when hitting max health.
     */
    size_t increaseHealthBy(const size_t amount);
    /*
     * Returns true when health has reached 0.
     */
    bool isDead() const;

    friend std::ostream& operator<< (std::ostream& out, const UnitHealth& unitHealth);

private:
    int _healthValue;
    int _healthMax;
};


#endif //RPGTEXTCPP_UNITHEALTH_H
