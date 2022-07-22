/* Citation and Sources...
Final Project Milestone 3
Module: Menu
Filename: Utils.cpp
Version 1.0
Author	Yongda Long
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#include "Utils.h"

using namespace std;

namespace sdds {
    unsigned int inputInt(int max) {
        unsigned int input = 0;
        cin >> input;
        while (input < 0 || input > (unsigned int)max || cin.fail()) {
            cin.clear();
            cin.ignore(2000, '\n');
            cout << "Invalid Selection, try again: ";
            cin >> input;
        }
        return input;
    }
}