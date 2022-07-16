/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: LibApp.cpp
Version 1.0
Author	Yongda Long
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#ifndef _SDDS_LIBAPP_H_
#define _SDDS_LIBAPP_H_

#include "Menu.h"
#include <iostream>

namespace sdds {
    class LibApp {
        bool m_changed;
        Menu m_mainMenu{"Seneca Library Application"};
        Menu m_exitMenu{"Changes have been made to the data, what would you like to do?"};

        bool confirm(const char *message) const;
        void load() const;
        void save() const;
        void search() const;
        void returnPub();
        void newPublication();
        void removePublication();
        void checkOutPub();

    public:
        LibApp();
        void run();
    };
}

#endif