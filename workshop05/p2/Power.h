/*
*****************************************************************************
Full Name : Yongda Long
Student ID# : 172800211
Email : ylong9@myseneca.ca
Section : OOP244NGG
Date : June 20, 2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_POWER_H
#define SDDS_POWER_H

namespace sdds {
    const int MAX_NAME_LENGTH = 50;

    class Power {
        char m_name[MAX_NAME_LENGTH + 1];
        int m_rarity;

    public:
        Power();
        Power(const char *name, int rarity);
        void setEmpty();
        void createPower(const char *name, int rarity);
        const char *checkName() const;
        int checkRarity() const;
        bool isEmpty() const;
    };
    void displayDetails(Power *powers, int size);
}
#endif