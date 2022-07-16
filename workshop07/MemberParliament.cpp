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

#include "MemberParliament.h"
#include <cstring>

namespace sdds {
    MemberParliament::MemberParliament(const char *id, int age) {
        m_age = age;
        strcpy(m_district, "Unassigned");

        if (id == nullptr) {
            m_id[0] = '\0';
            return;
        }

        strcpy(m_id, id);
    }

    void MemberParliament::setAge(int age) {
        m_age = age;
    }

    void MemberParliament::setDistrict(const char *district) {
        if (district != nullptr)
            strcpy(m_district, district);
    }

    void MemberParliament::NewDistrict(const char *district) {
        std::cout << "|";
        std::cout.setf(std::ios::right);
        std::cout.fill(' ');
        std::cout.width(8);
        std::cout << m_id << "| |";
        std::cout.width(20);
        std::cout << m_district;
        std::cout << " ---> ";
        setDistrict(district);
        std::cout.width(23);
        std::cout.unsetf(std::ios::right);
        std::cout.setf(std::ios::left);
        std::cout << m_district << "|" << std::endl;
    }

    std::ostream &MemberParliament::write(std::ostream &os) const {
        os << "| " << m_id << " | " << m_age << " | " << m_district;
        return os;
    }

    std::istream &MemberParliament::read(std::istream &is) {
        int age = 0;
        std::cout << "MP Age: ";
        is >> age;
        setAge(age);
        std::cout << "MP Id: ";
        is >> m_id;
        std::cout << "District: ";
        is >> m_district;
        std::cout << m_district << std::endl;
        return is;
    }

    std::ostream &operator<<(std::ostream &os, const MemberParliament &member) {
        member.write(os);
        return os;
    }

    std::istream &operator>>(std::istream &is, MemberParliament &member) {
        member.read(is);
        return is;
    }
}