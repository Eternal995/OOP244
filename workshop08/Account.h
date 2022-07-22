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

#ifndef _SDDS_ACCOUNT_H
#define _SDDS_ACCOUNT_H

#include "iAccount.h"

namespace sdds {
    class Account : public iAccount {
        double m_balance;

    protected:
        double balance() const;

    public:
        Account(double balance = 0.0);
        bool credit(double amount);
        bool debit(double amount);
    };
}

#endif