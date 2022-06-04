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

#include "Bar.h"

namespace sdds {
    class BarChart {
        char *title;
        Bar *bar;
        char fill;
        int size;
        int added;

    public:
        BarChart();
        void set_empty();
        void init(const char *title_in, int no, char fill_in);
        void add(const char *title_in, int no);
        void draw() const;
        void deallocate();
        bool is_filled() const;
        void reset_title();
        void reset_bar();
    };
}