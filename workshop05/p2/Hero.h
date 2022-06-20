/*
*****************************************************************************
Full Name : Yongda Long
Student ID# : 172800211
Email : ylong9@myseneca.ca
Section : OOP244NGG
Date : , 2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_HERO_H
#define SDDS_HERO_H

#include "Power.h"
#include <iostream>

namespace sdds {
    class Hero {
        char m_name[MAX_NAME_LENGTH];
        Power *m_power;
        int m_num_power;
        int m_power_level;

    public:
        Hero();
        Hero(const char *name, Power *power, int numPower);
        ~Hero();
        void setEmpty();
        int getPowerLevel() const;
        void updatePowerLevel();
        Hero &operator+=(Power &power);
        Hero &operator-=(int power);
        std::ostream &display(std::ostream &os = std::cout) const;
    };
    bool operator<(Hero &lhs, Hero &rhs);
    bool operator>(Hero &lhs, Hero &rhs);
    void operator<<(Hero &hero, Power &power);
    void operator>>(Power &power, Hero &hero);
    std::ostream &operator<<(std::ostream &os = std::cout, const Hero &hero);
}

#endif