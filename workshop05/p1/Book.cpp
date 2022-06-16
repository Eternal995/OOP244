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

#include "Book.h"
#include <cstring>

using namespace std;

namespace sdds {
    void Book::init_book() {
        m_title[0] = '\0';
        m_author[0] = '\0';
        m_num_chapters = 0;
        m_num_pages = 0;
    }

    Book::Book() {
        init_book();
    }

    Book::Book(const char *title_) {
        init_book();
        strcpy(m_title, title_);
    }

    Book::Book(const char *title_, const char *author_, double price_) {
        init_book();
        strcpy(m_title, title_);
        strcpy(m_author, author_);
        m_price = price_;
    }

    // Print a book summary
    void Book::summary() {
        cout.setf(ios::left);
        cout << "| ";
        cout.width(MAX_BOOK_TITLE);
        cout << m_title << " | ";
        cout.width(MAX_AUTHOR_NAME);
        cout << m_author << " | ";
        cout.width(3);
        cout << m_num_chapters << "  ";
        cout.width(4);
        cout << m_num_pages << " | ";
        cout.width(6);
        cout << m_price << " |" << endl;
    }

    int Book::add_chapter(Chapter *chapter) {
        if (m_num_chapters >= MAX_NUM_CHAPTERS)
            return m_num_chapters;

        m_chapters[m_num_chapters] = *chapter;
        m_num_pages += (int)*chapter;
        Book temp = *this;
        temp++;
        *this = temp;
        return m_num_chapters;
    }

    Book Book::operator++(int) {
        Book temp = *this;
        m_num_chapters++;
        return temp;
    }

    std::ostream &Book::display(std::ostream &os) const {
        os << "Title:'" << m_title << "'" << endl;
        os << "Author: '" << m_author << "'" << endl;
        for (int i = 0; i < m_num_chapters; i++) {
            m_chapters[i].display(os);
        }
        return os;
    }

    Book::operator int() const {
        return m_num_chapters;
    }

    Book::operator bool() const {
        if (m_title[0] == '\0' || m_author[0] == '\0' || m_num_chapters == 0)
            return false;

        for (int i = 0; i < m_num_chapters; i++) {
            if ((int)m_chapters[i] != 0)
                return true;
        }

        return false;
    }

    Book::operator double() const {
        return m_price;
    }

    Book::operator const char *() const {
        return m_title;
    }

    bool Book::operator!() {
        Book temp = *this;
        return !((bool)temp);
    }

    Book &Book::operator+=(Chapter &chapter) {
        add_chapter(&chapter);
        return *this;
    }

    Book &Book::operator-=(double price) {
        m_price -= price;
        return *this;
    }

    std::ostream &operator<<(std::ostream &os, const Book &book) {
        book.display(os);
        return os;
    }
}
