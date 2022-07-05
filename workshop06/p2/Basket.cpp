/*
*****************************************************************************
Full Name : Yongda Long
Student ID# : 172800211
Email : ylong9@myseneca.ca
Section : OOP244NGG
Date : July 4, 2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Basket.h"
#include <cstring>
#include <iomanip>

namespace sdds {
    Basket::Basket() {
        m_fruits = nullptr;
        m_cnt = 0;
        m_price = 0.0;
    }

    Basket::Basket(Fruit *fruit, int size, double price) {
        m_fruits = new Fruit[size];
        for (int i = 0; i < size; i++) {
            strcpy(m_fruits[i].m_name, fruit[i].m_name);
            m_fruits[i].m_qty = fruit[i].m_qty;
        }
        m_cnt = size;
        m_price = price;
    }

    Basket::Basket(const Basket &source) {
        m_cnt = source.m_cnt;
        m_price = source.m_price;
        m_fruits = new Fruit[m_cnt];

        for (int i = 0; i < m_cnt; i++) {
            strcpy(m_fruits[i].m_name, source.m_fruits[i].m_name);
            m_fruits[i].m_qty = source.m_fruits[i].m_qty;
        }
    }

    Basket &Basket::operator=(const Basket &source) {
        if (this == &source)
            return *this;

        if (m_fruits != nullptr) {
            delete[] m_fruits;
            m_fruits = nullptr;
        }

        m_cnt = source.m_cnt;
        m_price = source.m_price;
        m_fruits = new Fruit[m_cnt];

        for (int i = 0; i < m_cnt; i++) {
            strcpy(m_fruits[i].m_name, source.m_fruits[i].m_name);
            m_fruits[i].m_qty = source.m_fruits[i].m_qty;
        }

        return *this;
    }

    Basket::~Basket() {
        if (m_fruits != nullptr) {
            delete[] m_fruits;
            m_fruits = nullptr;
        }
    }

    void Basket::setPrice(double price) {
        m_price = price;
    }

    Basket::operator bool() const {
        return (m_cnt > 0);
    }

    Basket &Basket::operator+=(Fruit fruit) {
        Fruit *temp = nullptr;
        temp = new Fruit[m_cnt + 1];

        for (int i = 0; i < m_cnt; i++) {
            strcpy(temp[i].m_name, m_fruits[i].m_name);
            temp[i].m_qty = m_fruits[i].m_qty;
        }

        strcpy(temp[m_cnt].m_name, fruit.m_name);
        temp[m_cnt].m_qty = fruit.m_qty;

        delete[] m_fruits;

        m_fruits = temp;
        temp = nullptr;
        m_cnt++;

        return *this;
    }

    void Basket::display(std::ostream &os) const {
        if (!(*this)) {
            os << "The basket is empty!" << std::endl;
            return;
        }

        os << "Basket Content:" << std::endl;
        for (int i = 0; i < m_cnt; i++) {
            os.width(10);
            os.setf(std::ios::right);
            os << m_fruits[i].m_name << ": ";
            os.setf(std::ios::fixed);
            os.precision(2);
            os << m_fruits[i].m_qty << "kg" << std::endl;
        }
        os << "Price: " << m_price << std::endl;
    }

    std::ostream &operator<<(std::ostream &os, const Basket &basket) {
        basket.display(os);
        return os;
    }
}