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

#ifndef _SDDS_MEMBERPARLIAMENT_H_
#define _SDDS_MEMBERPARLIAMENT_H_

#include <iostream>

namespace sdds {
    const int MAX_ID_NUMBER = 32;
    const int MAX_DISTRICT_LENGTH = 64;
    class MemberParliament {
        char m_id[MAX_ID_NUMBER + 1];
        char m_district[MAX_DISTRICT_LENGTH + 1];
        int m_age;

    public:
        MemberParliament(const char *id = nullptr, int age = 0);
        void setAge(int age);
        void setDistrict(const char *district);
        void NewDistrict(const char *district);
        std::ostream &write(std::ostream &os = std::cout) const;
        std::istream &read(std::istream &is = std::cin);
    };
    std::ostream &operator<<(std::ostream &os, const MemberParliament &member);
    std::istream &operator>>(std::istream &is, MemberParliament &member);
}

#endif