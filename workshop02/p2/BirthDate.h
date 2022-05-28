/*
*****************************************************************************
Full Name : Yongda Long
Student ID# : 172800211
Email : ylong9@myseneca.ca
Section : OOP244NGG
Date : May 30, 2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

namespace sdds {
    struct Employee {
        char *name;
        int month;
        int day;
        int year;
    };
    bool openFile(const char *filename);
    bool beginSearch(const char *filename);
    int countBirthDate(int month);
    bool readBirthDate(int month);
    void sort();
    void displayBirthdays();
    void deallocate();
    void endSearch();
}