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

#include "BarChart.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds {
    BarChart::BarChart() {
        set_empty();
    }

    void BarChart::set_empty() {
        title = nullptr;
        bar = nullptr;
        fill = ' ';
        size = 0;
        added = 0;
    }

    void BarChart::init(const char *title_in, int no, char fill_in) {
        if (strcmp(title_in, "") == 0 || title_in == nullptr || no <= 0) {
            set_empty();
            return;
        }
        if (title != nullptr)
            reset_title();
        if (bar != nullptr)
            reset_bar();

        title = new char[strlen(title_in) + 1];
        strcpy(title, title_in);
        size = no;
        fill = fill_in;
        bar = new Bar[size];
        added = 0;
    }

    void BarChart::add(const char *title_in, int no) {
        if (is_filled())
            return;
        bar[added].set(title_in, fill, no);
        if (!bar[added].is_empty())
            added++;
    }

    void BarChart::draw() const {
        if (!is_filled()) {
            cout << "Invalid Chart!" << endl;
            return;
        }
        int i = 0;
        cout << title << endl;
        cout.fill('-');
        cout.width(71);
        cout << "-" << endl;
        for (i = 0; i < added; i++) {
            bar[i].draw();
        }
        cout.fill('-');
        cout.width(71);
        cout << "-" << endl;
    }

    void BarChart::reset_title() {
        delete[] title;
        title = nullptr;
    }

    void BarChart::reset_bar() {
        delete[] bar;
        bar = nullptr;
    }

    bool BarChart::is_filled() const {
        return (added == size);
    }

    void BarChart::deallocate() {
        for (int i = 0; i < added; i++) {
            if (!bar[i].is_empty())
                bar[i].reset();
        }
        reset_bar();
        reset_title();
    }
}