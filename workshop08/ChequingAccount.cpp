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

#include "ChequingAccount.h"
#include <iomanip>

namespace sdds {
    ChequingAccount::ChequingAccount(double balance, double transaction, double monthly) : Account(balance) {
        m_transaction = (transaction > 0.0) ? transaction : 0.0;
        m_monthly = (monthly > 0.0) ? monthly : 0.0;
    }

    bool ChequingAccount::credit(double amount) {
        if (Account::credit(amount)) {
            return Account::debit(m_transaction);
        }
        return false;
    }

    bool ChequingAccount::debit(double amount) {
        if (Account::debit(amount)) {
            return Account::debit(m_transaction);
        }
        return false;
    }

    void ChequingAccount::monthEnd() {
        Account::debit(m_monthly);
    }

    void ChequingAccount::display(std::ostream &os) const {
        os << "Account type: Chequing" << std::endl;
        os << "Balance: $";
        os.setf(std::ios::fixed);
        os.precision(2);
        os << balance() << std::endl;
        os << "Per Transaction Fee: " << m_transaction << std::endl;
        os << "Monthly Fee: " << m_monthly << std::endl;
    }
}