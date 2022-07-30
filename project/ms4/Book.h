/* Citation and Sources...
Final Project Milestone 4
Module: Book
Filename: Book.h
Version 1.0
Author	Yongda Long
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#ifndef _SDDS_BOOK_H_
#define _SDDS_BOOK_H_

#include "Publication.h"
#include <iostream>

namespace sdds {
    class Book : public Publication {
        char *m_author;

    public:
        Book();
        Book(const Book &source);
        Book &operator=(const Book &source);
        virtual ~Book();

        char type() const;
        void set(int id);
        std::ostream &write(std::ostream &os) const;
        std::istream &read(std::istream &is);
        operator bool() const;
    };
}

#endif