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

#ifndef _SDDS_NAME_H_
#define _SDDS_NAME_H_

#include <iostream>

namespace sdds {
    class Name {
        char *m_value;

    public:
        Name();
        Name(const char *name);
        Name(const Name &source);
        Name &operator=(const Name &source);
        ~Name();

        operator const char *() const;
        virtual operator bool() const;
        virtual std::ostream &display(std::ostream &os = std::cout) const;
        virtual std::istream &read(std::istream &is = std::cin);
    };

    std::ostream &operator<<(std::ostream &os, const Name &name);
    std::istream &operator>>(std::istream &is, Name &name);
}

#endif