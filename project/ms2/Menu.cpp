/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	Yongda Long
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#include "Menu.h"
#include "Utils.h"
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

namespace sdds {
    MenuItem::MenuItem() {
        m_content = nullptr;
    }

    MenuItem::MenuItem(const char *content) {
        if (content == nullptr) {
            m_content = nullptr;
            return;
        }

        m_content = new char[strlen(content) + 1];
        strcpy(m_content, content);
    }

    MenuItem::~MenuItem() {
        if (m_content != nullptr)
            delete[] m_content;
        m_content = nullptr;
    }

    void MenuItem::set(const char *content) {
        if (m_content != nullptr) {
            delete[] m_content;
            m_content = nullptr;
        }

        m_content = new char[strlen(content) + 1];
        strcpy(m_content, content);
    }

    MenuItem::operator bool() const {
        return (m_content != nullptr);
    }

    MenuItem::operator const char *() const {
        return m_content;
    }

    std::ostream &MenuItem::display(std::ostream &os) const {
        if (m_content != nullptr)
            os << m_content;
        return os;
    }

    Menu::Menu() {
        m_title.m_content = nullptr;
        for (int i = 0; i < MAX_MENU_ITEMS; i++) {
            m_item[i] = nullptr;
        }
        m_count = 0;
    }

    Menu::Menu(const char *title) {
        if (title == nullptr) {
            m_title.m_content = nullptr;
        } else {
            m_title.m_content = new char[strlen(title) + 1];
            strcpy(m_title.m_content, title);
        }
        for (int i = 0; i < MAX_MENU_ITEMS; i++) {
            m_item[i] = nullptr;
        }
        m_count = 0;
    }

    Menu::~Menu() {
        for (int i = 0; i < m_count; i++) {
            delete m_item[i];
            m_item[i] = nullptr;
        }
    }

    std::ostream &Menu::displayTitle(std::ostream &os) const {
        m_title.display(os);
        return os;
    }

    std::ostream &Menu::display(std::ostream &os) const {
        if (m_title != nullptr) {
            m_title.display(os);
            os << std::endl;
        }
        for (int i = 0; i < m_count; i++) {
            // os.setf(ios::fixed);
            os.width(2);
            os.fill(' ');
            os << i + 1 << "- ";
            m_item[i]->display(os);
            os << endl;
        }
        os << " 0- Exit" << endl;
        os << "> ";
        return os;
    }

    unsigned int Menu::run() const {
        display();
        return inputInt(m_count);
    }

    unsigned int Menu::operator~() const {
        display();
        return inputInt(m_count);
    }

    Menu &Menu::operator<<(const char *item) {
        if (m_count == MAX_MENU_ITEMS) {
            return *this;
        }
        m_item[m_count] = new MenuItem(item);
        m_count++;
        return *this;
    }

    Menu::operator int() const {
        return m_count;
    }

    Menu::operator unsigned int() const {
        return m_count;
    }

    Menu::operator bool() const {
        return (m_count != 0);
    }

    const char *Menu::operator[](const int index) const {
        if (index <= m_count) {
            return m_item[index]->m_content;
        } else {
            return m_item[index % m_count]->m_content;
        }
    }

    std::ostream &operator<<(std::ostream &os, const Menu &menu) {
        menu.displayTitle(os);
        return os;
    }
}
