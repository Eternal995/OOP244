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

#ifndef SDDS_BOOK_H_
#define SDDS_BOOK_H_

#include "Chapter.h"
#include <iostream>

namespace sdds {
    const int MAX_NUM_CHAPTERS = 10;
    const int MAX_BOOK_TITLE = 40;
    const int MAX_AUTHOR_NAME = 20;

    class Book {
        char m_title[MAX_BOOK_TITLE + 1];
        char m_author[MAX_AUTHOR_NAME + 1];
        int m_num_chapters;
        int m_num_pages;
        double m_price;
        Chapter m_chapters[MAX_NUM_CHAPTERS];

        void init_book();
        int add_chapter(Chapter *chapter);

    public:
        Book();
        Book(const char *title_);
        Book(const char *title_, const char *author_, double price_);
        void summary(); // Print a book summary
        Book operator++(int);
        std::ostream &display(std::ostream &os) const;
        operator int() const;
        operator bool() const;
        operator double() const;
        operator const char *() const;
        bool operator!();
        Book &operator+=(Chapter &chapter);
        Book &operator-=(double price);
    };

    std::ostream &operator<<(std::ostream &os, const Book &book);
}

#endif
