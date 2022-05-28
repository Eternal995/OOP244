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

#include "BirthDate.h"
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds {
    Employee *employee = nullptr;
    FILE *fp;
    int countBirthDates = 0;

    bool openFile(const char *filename) {
        fp = fopen(filename, "r");
        return fp != NULL;
    }

    bool beginSearch(const char *filename) {
        if (!openFile(filename)) {
            cout << "Data file \"" << filename << "\" not found!" << endl;
            return false;
        }
        cout << "Birthdate search program" << endl;
        return true;
    }

    int countBirthDate(int month) {
        int count = 0;
        char tempName[31];
        int tempMonth, tempDate, tempYear;
        while (fscanf(fp, "%[^,],%d/%d/%d\n", tempName, &tempMonth, &tempDate, &tempYear) == 4) {
            if (tempMonth == month)
                count++;
        }
        rewind(fp);
        return count;
    }

    bool readBirthDate(int month) {
        countBirthDates = countBirthDate(month);
        if (countBirthDates == 0)
            return false;
        cout << countBirthDates << " birthdates found:" << endl;
        employee = new Employee[countBirthDates];
        int i = 0;
        char temp[31];
        int tempMonth, tempDate, tempYear;
        while (i < countBirthDates) {
            fscanf(fp, "\n%[^,],%d/%d/%d", temp, &tempMonth, &tempDate, &tempYear);
            if (tempMonth == month) {
                employee[i].name = new char[strlen(temp) + 1];
                strcpy(employee[i].name, temp);
                employee[i].month = tempMonth;
                employee[i].day = tempDate;
                employee[i].year = tempYear;
                i++;
            }
        }
        return true;
    }

    void sort() {
        int i, j;
        Employee temp;
        for (i = countBirthDates - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employee[j].year > employee[j + 1].year) {
                    temp = employee[j];
                    employee[j] = employee[j + 1];
                    employee[j + 1] = temp;
                }
            }
        }
    }

    void displayBirthdays() {
        int i;
        for (i = 0; i < countBirthDates; i++) {
            cout << i + 1 << ") " << employee[i].name << ":" << endl;
            cout << employee[i].year << "-" << employee[i].month << "-" << employee[i].day << endl;
            cout << "===================================" << endl;
        }
    }

    void deallocate() {
        for (int i = 0; i < countBirthDates; i++) {
            delete[] employee[i].name;
            employee[i].name = nullptr;
        }
        delete[] employee;
        employee = nullptr;
    }

    void endSearch() {
        if (fp)
            fclose(fp);
        cout << "Birthdate Search Program Closed." << endl;
    }
}