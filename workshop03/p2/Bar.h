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

namespace sdds {
    class Bar {
        char *title;
        char fill;
        int no;

    public:
        Bar();
        void set_empty();
        void set(const char *title_in, char fill_in, int no_in);
        void draw() const;
        bool is_empty() const;
        void reset();
    };
}