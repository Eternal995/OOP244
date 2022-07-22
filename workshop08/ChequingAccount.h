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

#ifndef _SDDS_CHEQUING_H
#define _SDDS_CHEQUING_H

#include "Account.h"

namespace sdds {
    class ChequingAccount : public Account {
        double m_transaction;
        double m_monthly;

    public:
        ChequingAccount(double balance = 0.0, double transaction = 0.0, double monthly = 0.0);
        bool credit(double amount);
        bool debit(double amount);
        void monthEnd();
        void display(std::ostream &os) const;
    };
}

#endif