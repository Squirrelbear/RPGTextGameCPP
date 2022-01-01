//
// Created by Peter on 27/12/2021.
//

#ifndef RPGTEXTCPP_UNITSTAT_H
#define RPGTEXTCPP_UNITSTAT_H

#include <iostream>

// Defines a generic UnitStat that is based on having a maximum with an increasing or decreasing current value.
class UnitStat {
public:
    // Defines a UnitStat setting the current and maximum values to the statMax.
    explicit UnitStat(const size_t statMax);
    /*
     * Sets the maximum stat AND current stat to statMax if changeCurrent is true.
     */
    void setStatMax(const size_t statMax, const bool changeCurrent = true);
    // Gets the maximum value possible for this stat.
    int getStatMax() const;
    // Gets the current value of this stat.
    int getStatValue() const;

    // Returns true if the current stat is 0.
    bool hasZeroStat() const;

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

    /*
     * Outputs in the form:
     * {value} of {max}
     */
    friend std::ostream& operator<< (std::ostream& out, const UnitStat& unitStat);

private:
    // The current stat value.
    int _statValue;
    // The maximum stat value.
    int _statMax;
};


#endif //RPGTEXTCPP_UNITSTAT_H
