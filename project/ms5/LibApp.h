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
#include "Publication.h"

namespace sdds {
    class LibApp {
        bool m_changed;
        Menu m_mainMenu;
        Menu m_exitMenu;
        char m_file[SDDS_FILE_NAME];
        Publication *m_pub[SDDS_LIBRARY_CAPACITY];
        int m_numLoaded;
        int m_lastRef;
        Menu m_type;

        bool confirm(const char *message) const;
        void load();
        void save() const;
        int search(int mode) const;
        Publication *getPub(int libRef) const;
        void newPublication();
        void removePublication();
        void checkOutPub();
        void returnPub();

      public:
        LibApp(const char *file);
        ~LibApp();
        LibApp(const LibApp &source) = delete;
        LibApp &operator=(const LibApp &source) = delete;
        void run();
    };
}

#endif