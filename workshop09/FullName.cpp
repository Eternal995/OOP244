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

#include "FullName.h"
#include <cstring>

namespace sdds {
    FullName::FullName() {
        m_value = nullptr;
    }

    FullName::FullName(const char *name, const char *lastName) : Name(name) {
        if (lastName == nullptr) {
            m_value = nullptr;
            return;
        }

        m_value = new char[strlen(lastName) + 1];
        strcpy(m_value, lastName);
    }

    FullName::FullName(const FullName &source) : Name(source) {
        if (source.m_value == nullptr) {
            m_value = nullptr;
            return;
        }

        m_value = new char[strlen(source.m_value) + 1];
        strcpy(m_value, source.m_value);
    }

    FullName &FullName::operator=(const FullName &source) {
        if (this == &source)
            return *this;

        Name::operator=(source);

        if (m_value != nullptr)
            delete[] m_value;

        m_value = nullptr;

        if (source.m_value != nullptr) {
            m_value = new char[strlen(source.m_value) + 1];
            strcpy(m_value, source.m_value);
        }

        return *this;
    }

    FullName::~FullName() {
        if (m_value != nullptr)
            delete[] m_value;
    }

    FullName::operator const char *() const {
        return m_value;
    }

    FullName::operator bool() const {
        return (Name::operator bool() && (m_value != nullptr));
    }

    std::ostream &FullName::display(std::ostream &os) const {
        if (*this) {
            Name::display(os);
            os << " " << m_value;
        }
        return os;
    }

    std::istream &FullName::read(std::istream &is) {
        Name::read(is);
        char temp[21];
        is.get(temp, 20, '\n');
        if (temp[0] != '\0') {
            m_value = new char[strlen(temp) + 1];
            strcpy(m_value, temp);
            is.ignore(1);
        }
        return is;
    }
}