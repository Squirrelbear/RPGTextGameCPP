//
// Created by Peter on 27/12/2021.
//

#ifndef RPGTEXTCPP_UNITSTAT_H
#define RPGTEXTCPP_UNITSTAT_H

#include <iostream>

class UnitStat {
public:
    explicit UnitStat(const size_t statMax);
    /*
     * Sets the maximum stat AND current stat to statMax if changeCurrent is true.
     */
    void setStatMax(const size_t statMax, const bool changeCurrent = true);
    int getStatMax() const;
    int getStatValue() const;
    /*
     * Decreases stat value by up to amount. Will not reduce below 0.
     * Returns the amount it was reduced by.
     */
    size_t decreaseStatBy(const size_t amount);
    /*
     * Increases mana value by up to amount. Will not increase above max mana.
     * Returns the actual restore applied, which will vary when hitting max mana.
     */
    size_t increaseStatBy(const size_t amount);

    friend std::ostream& operator<< (std::ostream& out, const UnitStat& unitStat);

private:
    int _statValue;
    int _statMax;
};


#endif //RPGTEXTCPP_UNITSTAT_H
