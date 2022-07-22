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

#include "Account.h"

namespace sdds {
    double Account::balance() const {
        return m_balance;
    }

    Account::Account(double balance) {
        m_balance = (balance > 0.0) ? balance : 0.0;
    }

    bool Account::credit(double amount) {
        if (amount <= 0.0) {
            return false;
        }
        m_balance += amount;
        return true;
    }

    bool Account::debit(double amount) {
        if (amount <= 0.0) {
            return false;
        }
        m_balance -= amount;
        return true;
    }
}