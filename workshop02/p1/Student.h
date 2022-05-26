/*
*****************************************************************************
Full Name : Yongda Long
Student ID# : 172800211
Email : ylong9@myseneca.ca
Section : OOP244NGG
Date : May 26, 2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H
#include "File.h"

namespace sdds {
    struct Student {
        char *name;
        int no;
        char grade;
    };
    void sort();
    bool load(Student *student);
    bool load(const char *filename);
    void display(Student *student);
    void display();
    void deallocateMemory();
}

#endif
