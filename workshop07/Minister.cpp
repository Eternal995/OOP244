/*
*****************************************************************************
Full Name : Yongda Long
Student ID# : 172800211
Email : ylong9@myseneca.ca
Section : OOP244NGG
Date : July 15, 2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Minister.h"
#include <cstring>

namespace sdds {
    Minister::Minister(const char *id, int age, int year, const char *district, const char *pm)
        : MemberParliament(id, age) {
        NewDistrict(district);
        changePM(pm);
        assumeOffice(year);
    }

    void Minister::changePM(const char *pm) {
        if (pm != nullptr)
            strcpy(m_reportsto, pm);
    }

    void Minister::assumeOffice(int year) {
        m_year = year;
    }

    std::ostream &Minister::write(std::ostream &os) const {
        MemberParliament::write(os);
        os << " | " << m_reportsto << "/" << m_year;
        return os;
    }

    std::istream &Minister::read(std::istream &is) {
        MemberParliament::read(is);
        std::cout << "Reports TO: ";
        is >> m_reportsto;
        std::cout << "Year Assumed Office: ";
        is >> m_year;
        return is;
    }

    std::ostream &operator<<(std::ostream &os, const Minister &minister) {
        minister.write(os);
        return os;
    }

    std::istream &operator>>(std::istream &is, Minister &minister) {
        minister.read(is);
        return is;
    }
}