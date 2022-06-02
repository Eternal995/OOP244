/*
*****************************************************************************
Full Name : Yongda Long
Student ID# : 172800211
Email : ylong9@myseneca.ca
Section : OOP244NGG
Date : June 2, 2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

namespace sdds {
    const int MAX_NAME_LEN = 50;
    class Army {
        char nationality[MAX_NAME_LEN];
        int units;
        double power;

    public:
        void setEmpty();
        void createArmy(const char *country, double pow, int troops);
        void updateUnits(int troops);
        const char *checkNationality() const;
        int checkCapacity() const;
        double checkPower() const;
        bool isEmpty() const;
        bool isStrongerThan(const Army &army) const;
    };
    void battle(Army &arm1, Army &arm2);
    void displayDetails(const Army *armies, int size);

}