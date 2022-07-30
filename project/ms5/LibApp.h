/* Citation and Sources...
Final Project Milestone 5
Module: LibApp
Filename: LibApp.h
Version 1.0
Author	Yongda Long
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#ifndef _SDDS_LIBAPP_H_
#define _SDDS_LIBAPP_H_

#include <iostream>

#include "Menu.h"

namespace sdds {
    class LibApp {
        bool m_changed;
        Menu m_mainMenu;
        Menu m_exitMenu;

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