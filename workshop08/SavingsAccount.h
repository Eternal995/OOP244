/*
*****************************************************************************
Full Name : Yongda Long
Student ID# : 172800211
Email : ylong9@myseneca.ca
Section : OOP244NGG
Date : July 22, 2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef _SDDS_SAVING_H
#define _SDDS_SAVING_H

#include "Account.h"

namespace sdds {
    class SavingsAccount : public Account {
        double m_rate;

    public:
        SavingsAccount(double balance = 0.0, double rate = 0.0);
        void monthEnd();
        void display(std::ostream &os) const;
    };
}

#endif