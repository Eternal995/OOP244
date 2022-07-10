/* Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.h
Version 1.0
Author	Yongda Long
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#ifndef _SDDS_MENU_H_
#define _SDDS_MENU_H_

#include <iostream>

namespace sdds {
    const int MAX_MENU_ITEMS = 20;

    class Menu;

    class MenuItem {
        char *m_content;

        friend class Menu;

        MenuItem();
        MenuItem(const char *content);
        MenuItem(const MenuItem &source) = delete;
        MenuItem &operator=(const MenuItem &source) = delete;
        ~MenuItem();
        void set(const char *content);
        operator bool() const;
        operator const char *() const;
        std::ostream &display(std::ostream &os = std::cout) const;
    };

    class Menu {
        MenuItem m_title;
        MenuItem *m_item[MAX_MENU_ITEMS];
        int m_count;

    public:
        Menu();
        Menu(const char *title);
        Menu(const Menu &source) = delete;
        Menu &operator=(const Menu &source) = delete;
        ~Menu();
        std::ostream &displayTitle(std::ostream &os = std::cout) const;
        std::ostream &display(std::ostream &os = std::cout) const;
        unsigned int run() const;
        unsigned int operator~() const;
        Menu &operator<<(const char *item);
        operator int() const;
        operator unsigned int() const;
        operator bool() const;
        const char *operator[](const int index) const;
    };

    std::ostream &operator<<(std::ostream &os, const Menu &menu);
}

#endif