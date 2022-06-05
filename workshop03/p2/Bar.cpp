/*
*****************************************************************************
Full Name : Yongda Long
Student ID# : 172800211
Email : ylong9@myseneca.ca
Section : OOP244NGG
Date : June 4, 2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Bar.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds {
    void Bar::set_empty() {
        title = nullptr;
        fill = ' ';
        no = 0;
    }

    Bar::Bar() {
        set_empty();
    }

    void Bar::set(const char *title_in, char fill_in, int no_in) {
        if (strcmp(title_in, "") == 0 || title_in == nullptr || no_in <= 0 || no_in > 100) {
            set_empty();
            return;
        }

        if (title != nullptr)
            reset();

        int len = 20;
        if (strlen(title_in) < 20)
            len = strlen(title_in);
        title = new char[len + 1];
        strcpy(title, title_in);
        fill = fill_in;
        no = no_in;
    }

    void Bar::draw() const {
        if (is_empty())
            return;

        cout.fill('.');
        cout.width(20);
        cout.setf(ios::left);
        cout << title << "|";
        cout.unsetf(ios::left);
        for (int i = 0; i < (no / 2); i++)
            cout << fill;
        cout << endl;
    }

    bool Bar::is_empty() const {
        return (title == nullptr);
    }

    void Bar::reset() {
        delete[] title;
        title = nullptr;
    }
}