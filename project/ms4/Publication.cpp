/* Citation and Sources...
Final Project Milestone 4
Module: Publication
Filename: Publication.cpp
Version 1.0
Author	Yongda Long
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#include "Publication.h"
#include <cstring>
#include <iomanip>

namespace sdds {
    Publication::Publication() {
        m_title = nullptr;
        m_shelfID[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        m_date = Date();
    }

    Publication::Publication(const Publication &source) {
        if (source.m_title != nullptr) {
            m_title = new char[strlen(source.m_title) + 1];
            strcpy(m_title, source.m_title);
        }
        strcpy(m_shelfID, source.m_shelfID);
        m_membership = source.m_membership;
        m_libRef = source.m_libRef;
        m_date = source.m_date;
    }

    Publication &Publication::operator=(const Publication &source) {
        if (this == &source)
            return *this;

        if (m_title != nullptr) {
            delete[] m_title;
            m_title = nullptr;
        }

        if (source.m_title != nullptr) {
            m_title = new char[strlen(source.m_title) + 1];
            strcpy(m_title, source.m_title);
        }
        strcpy(m_shelfID, source.m_shelfID);
        m_membership = source.m_membership;
        m_libRef = source.m_libRef;
        m_date = source.m_date;
        return *this;
    }

    Publication::~Publication() {
        delete[] m_title;
    }

    void Publication::set(int member_id) {
        m_membership = (member_id >= 10000 && member_id <= 99999) ? member_id : 0;
    }

    void Publication::setRef(int value) {
        m_libRef = value;
    }

    void Publication::resetDate() {
        m_date = Date();
    }

    char Publication::type() const {
        return 'P';
    }

    bool Publication::onLoan() const {
        return (m_membership != 0);
    }

    Date Publication::checkoutDate() const {
        return m_date;
    }

    bool Publication::operator==(const char *title) const {
        return (strstr(m_title, title) != nullptr);
    }

    Publication::operator const char *() const {
        return m_title;
    }

    int Publication::getRef() const {
        return m_libRef;
    }

    bool Publication::conIO(std::ios &io) const {
        return (&io == &std::cout || &io == &std::cin);
    }

    std::ostream &Publication::write(std::ostream &os) const {
        if (conIO(os)) {
            os.setf(std::ios::left);
            os << "| " << m_shelfID << " | ";
            if (strlen(m_title) > SDDS_TITLE_WIDTH) {
                for (int i = 0; i < SDDS_TITLE_WIDTH; i++)
                    os << m_title[i];
            } else {
                os.fill('.');
                os.width(SDDS_TITLE_WIDTH);
                os << m_title;
            }
            os << " | ";
            if (onLoan()) {
                os << m_membership;
            } else {
                os << " N/A ";
            }
            os << " | " << m_date << " |";
            os.unsetf(std::ios::left);
            os.fill(' ');
            return os;
        }
        os << type() << "\t" << m_libRef << "\t" << m_shelfID << "\t" << m_title << "\t";
        if (onLoan()) {
            os << m_membership;
        } else {
            os << " N/A ";
        }
        os << "\t" << m_date;
        return os;
    }

    std::istream &Publication::read(std::istream &is) {
        if (m_title != nullptr) {
            delete[] m_title;
            m_title = nullptr;
        }
        m_shelfID[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        m_date = Date();

        char temp_shelfID[SDDS_SHELF_ID_LEN + 1];
        char temp_title[256];
        int temp_membership = 0, temp_libRef = -1;
        Date temp_date;

        if (conIO(is)) {
            std::cout << "Shelf No: ";
            is.getline(temp_shelfID, SDDS_SHELF_ID_LEN + 1);
            if (strlen(temp_shelfID) != SDDS_SHELF_ID_LEN)
                is.setstate(std::ios::failbit);
            std::cout << "Title: ";
            is.getline(temp_title, 256);
            std::cout << "Date: ";
            if (is)
                temp_date.read(is);
        } else {
            is >> temp_libRef;
            is.ignore();
            is.getline(temp_shelfID, SDDS_SHELF_ID_LEN + 1, '\t');
            is.getline(temp_title, 256, '\t');
            is >> temp_membership;
            is.ignore();
            is >> temp_date;
        }

        if (!temp_date)
            is.setstate(std::ios::failbit);

        if (is) {
            m_title = new char[strlen(temp_title) + 1];
            strcpy(m_title, temp_title);
            strcpy(m_shelfID, temp_shelfID);
            m_membership = temp_membership;
            m_date = temp_date;
            m_libRef = temp_libRef;
        }

        return is;
    }

    Publication::operator bool() const {
        return (m_title && (m_title[0] != '\0') && (m_shelfID[0] != '\0'));
    }
}