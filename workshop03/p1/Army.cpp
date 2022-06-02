/*
*****************************************************************************
Full Name : Yongda Long
Student ID# : 172800211
Email : ylong9@myseneca.ca
Section : OOP244NGG
Date : June 2, 2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Army.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds {
    void Army::setEmpty() {
        strcpy(nationality, "");
        units = 0;
        power = 0.0;
    }

    void Army::createArmy(const char *country, double pow, int troops) {
        if (country == nullptr || strlen(country) == 0 || pow == 0.0 || troops == 0) {
            setEmpty();
            return;
        }
        strcpy(nationality, country);
        units = troops;
        power = pow;
    }

    void Army::updateUnits(int troops) {
        units += troops;
        power += (double)troops / 4.;
    }

    const char *Army::checkNationality() const {
        return nationality;
    }

    int Army::checkCapacity() const {
        return units;
    }

    double Army::checkPower() const {
        return power;
    }

    bool Army::isEmpty() const {
        if (strcmp(nationality, "") == 0 && units == 0)
            return true;
        return false;
    }

    bool Army::isStrongerThan(const Army &army) const {
        if (power > army.power)
            return true;
        return false;
    }

    void battle(Army &arm1, Army &arm2) {
        if (arm1.isEmpty() || arm2.isEmpty())
            return;

        cout << "In battle of " << arm1.checkNationality() << " and ";
        cout << arm2.checkNationality() << ", ";

        if (arm1.isStrongerThan(arm2)) {
            cout << arm1.checkNationality() << " is victorious!" << endl;
            arm2.updateUnits(-arm2.checkCapacity() / 2);
            return;
        }
        cout << arm2.checkNationality() << " is victorious!" << endl;
        arm1.updateUnits(-arm1.checkCapacity() / 2);
    }

    void displayDetails(const Army *armies, int size) {
        cout << "Armies reporting to battle: " << endl;
        for (int i = 0; i < size; i++) {
            if (!armies[i].isEmpty()) {
                cout << "Nationality: " << armies[i].checkNationality() << ", Units Count: ";
                cout << armies[i].checkCapacity() << ", Power left: ";
                cout << fixed;
                cout.precision(1);
                cout << armies[i].checkPower() << endl;
            }
        }
    }
}