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

#include "Name.h"
#include <cstring>

namespace sdds {

    Name::Name() {
        m_value = nullptr;
    }

    Name::Name(const char *name) {
        if (name == nullptr) {
            m_value = nullptr;
            return;
        }

        m_value = new char[strlen(name) + 1];
        strcpy(m_value, name);
    }

    Name::Name(const Name &source) {
        if (source.m_value == nullptr) {
            m_value = nullptr;
            return;
        }

        m_value = new char[strlen(source.m_value) + 1];
        strcpy(m_value, source.m_value);
    }

    Name &Name::operator=(const Name &source) {
        if (this == &source)
            return *this;

        if (m_value != nullptr)
            delete[] m_value;

        m_value = nullptr;

        if (source.m_value != nullptr) {
            m_value = new char[strlen(source.m_value) + 1];
            strcpy(m_value, source.m_value);
        }

        return *this;
    }

    Name::~Name() {
        if (m_value != nullptr)
            delete[] m_value;
    }

    Name::operator const char *() const {
        return m_value;
    }

    Name::operator bool() const {
        return (m_value != nullptr && m_value[0] != '\0');
    }

    std::ostream &Name::display(std::ostream &os) const {
        if (*this) {
            os << m_value;
        }
        return os;
    }

    std::istream &Name::read(std::istream &is) {
        char temp[21];
        is.get(temp, 20, ' ');
        if (temp[0] != '\0') {
            m_value = new char[strlen(temp) + 1];
            strcpy(m_value, temp);
            is.ignore(1);
        }
        return is;
    }

    std::ostream &operator<<(std::ostream &os, const Name &name) {
        name.display(os);
        return os;
    }

    std::istream &operator>>(std::istream &is, Name &name) {
        name.read(is);
        return is;
    }
}