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

#ifndef _SDDS_IACCOUNT_H
#define _SDDS_IACCOUNT_H

#include <iostream>

namespace sdds {
    class iAccount {
    public:
        virtual bool credit(double amount) = 0;
        virtual bool debit(double amount) = 0;
        virtual void monthEnd() = 0;
        virtual void display(std::ostream &os) const = 0;
        virtual ~iAccount() {}
    };
    iAccount *CreateAccount(const char *, double);
}

#endif