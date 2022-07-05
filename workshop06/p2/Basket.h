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
#ifndef _SDDS_BASKET_H_
#define _SDDS_BASKET_H_

#include <iostream>

namespace sdds {

    struct Fruit {
        char m_name[30 + 1]; // the name of the fruit
        double m_qty;        // quantity in kilograms
    };

    class Basket {
        Fruit *m_fruits;
        int m_cnt;
        double m_price;

    public:
        Basket();
        Basket(Fruit *fruit, int size, double price);
        Basket(const Basket &source);
        Basket &operator=(const Basket &source);
        ~Basket();
        void setPrice(double price);
        operator bool() const;
        Basket &operator+=(Fruit fruit);
        void display(std::ostream &os) const;
    };

    std::ostream &operator<<(std::ostream &os, const Basket &basket);
}

#endif