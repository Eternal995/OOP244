/* Citation and Sources...
Final Project Milestone 5
Module: Book
Filename: Book.cpp
Version 1.0
Author	Yongda Long
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#include "Book.h"

#include <cstring>

namespace sdds {
    Book::Book() {
        m_author = nullptr;
    }

    Book::Book(const Book &source) : Publication(source) {
        if (source.m_author == nullptr || source.m_author[0] == '\0') {
            m_author = nullptr;
            return;
        }

        m_author = new char[strlen(source.m_author) + 1];
        strcpy(m_author, source.m_author);
    }

    Book &Book::operator=(const Book &source) {
        if (this == &source)
            return *this;

        Publication::operator=(source);

        if (m_author != nullptr)
            delete[] m_author;

        if (source.m_author == nullptr || source.m_author[0] == '\0') {
            m_author = nullptr;
            return *this;
        }

        m_author = new char[strlen(source.m_author) + 1];
        strcpy(m_author, source.m_author);
        return *this;
    }

    Book::~Book() {
        if (m_author != nullptr) {
            delete[] m_author;
            m_author = nullptr;
        }
    }

    char Book::type() const {
        return 'B';
    }

    void Book::set(int id) {
        Publication::set(id);
        Publication::resetDate();
    }

    std::ostream &Book::write(std::ostream &os) const {
        Publication::write(os);
        if (Publication::conIO(os)) {
            os << " ";
            os.setf(std::ios::left);
            if (strlen(m_author) > SDDS_AUTHOR_WIDTH) {
                for (int i = 0; i < SDDS_AUTHOR_WIDTH; i++)
                    os << m_author[i];
            } else {
                os.width(SDDS_AUTHOR_WIDTH);
                os.fill(' ');
                os << m_author;
            }
            os << " |";
            os.unsetf(std::ios::left);
        } else {
            os << '\t' << m_author;
        }
        return os;
    }

    std::istream &Book::read(std::istream &is) {
        Publication::read(is);

        if (m_author != nullptr) {
            delete[] m_author;
            m_author = nullptr;
        }

        char temp[256]{};

        if (Publication::conIO(is)) {
            is.ignore();
            std::cout << "Author: ";
            is.get(temp, 256);
        } else {
            is.ignore();
            is.get(temp, 256);
        }

        if (is) {
            m_author = new char[strlen(temp) + 1];
            strcpy(m_author, temp);
        }

        return is;
    }

    Book::operator bool() const {
        return (m_author && (m_author[0] != '\0') && Publication::operator bool());
    }
}