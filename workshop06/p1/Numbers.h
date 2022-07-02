/*
*****************************************************************************
Full Name : Yongda Long
Student ID# : 172800211
Email : ylong9@myseneca.ca
Section : OOP244NGG
Date : July 1, 2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_

#include <iostream>

namespace sdds {
    class Numbers {
        double *m_numbers;
        char *m_filename;
        bool m_isOriginal;
        int m_numCount;
        bool isEmpty() const;
        void setEmpty();
        void setFilename(const char *filename);
        void sort();

    public:
        Numbers();
        Numbers(const char *filename);
        Numbers(const Numbers &source);
        Numbers &operator=(const Numbers &source);
        double average() const;
        double max() const;
        double min() const;
        ~Numbers();
        int numberCount() const;
        bool load();
        void save() const;
        Numbers &operator+=(double number);
        std::ostream &display(std::ostream &os) const;
    };
    std::ostream &operator<<(std::ostream &os, const Numbers &N);
    std::istream &operator>>(std::istream &is, Numbers &N);
}
#endif // !SDDS_NUMBERS_H_

