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

#include "SavingsAccount.h"
#include <iomanip>

namespace sdds {
    SavingsAccount::SavingsAccount(double balance, double rate) : Account(balance) {
        m_rate = (rate > 0.0) ? rate : 0.0;
    }

    void SavingsAccount::monthEnd() {
        credit(balance() * m_rate);
    }

    void SavingsAccount::display(std::ostream &os) const {
        os << "Account type: Savings" << std::endl;
        os << "Balance: $";
        os.setf(std::ios::fixed);
        os.precision(2);
        os << balance() << std::endl;
        os << "Interest Rate (%): " << m_rate * 100 << std::endl;
    }
}