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

#ifndef _SDDS_MINISTER_H_
#define _SDDS_MINISTER_H_

#include "MemberParliament.h"

namespace sdds {
    const int MAX_REPORTS_TO = 50;

    class Minister : public MemberParliament {
        char m_reportsto[MAX_REPORTS_TO + 1];
        int m_year;

    public:
        Minister(const char *id = nullptr, int age = 0, int year = 0, const char *pm = nullptr, const char *district = nullptr);
        void changePM(const char *pm);
        void assumeOffice(int year);
        std::ostream &write(std::ostream &os = std::cout) const;
        std::istream &read(std::istream &is = std::cin);
    };
    std::ostream &operator<<(std::ostream &os, const Minister &minister);
    std::istream &operator>>(std::istream &is, Minister &minister);
}

#endif