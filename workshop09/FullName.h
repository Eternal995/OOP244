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

#ifndef _SDDS_FULLNAME_H_
#define _SDDS_FULLNAME_H_

#include "Name.h"

namespace sdds {
    class FullName : public Name {
        char *m_value;

    public:
        FullName();
        FullName(const char *name, const char *lastName);
        FullName(const FullName &source);
        FullName &operator=(const FullName &source);
        ~FullName();

        operator const char *() const;
        virtual operator bool() const;
        virtual std::ostream &display(std::ostream &os = std::cout) const;
        virtual std::istream &read(std::istream &is = std::cin);
    };
}

#endif