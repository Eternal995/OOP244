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

#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
using namespace sdds;

namespace sdds {

    int noOFStudents = 0;

    Student *students;

    void sort() {
        int i, j;
        Student temp;
        for (i = noOFStudents - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (students[j].grade > students[j + 1].grade) {
                    temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
    }

    bool load(Student *student) {

        char temp[128];

        if (!(read(temp) && read(student->no) && read(student->grade)))
            return false;

        student->name = new char[strlen(temp) + 1];

        strcpy(student->name, temp);

        return true;
    }

    bool load(const char *filename) {

        if (!openFile(filename))
            return false;

        noOFStudents = noOfRecords();

        students = new Student[noOFStudents];

        for (int i = 0; i < noOFStudents; i++) {
            if (!load(&students[i])) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted.";
                cout << endl;
                return false;
            }
        }

        closeFile();

        return true;
    }

    void display(Student *student) {
        cout << student->name << ", " << student->no << ": " << student->grade << endl;
    }

    void display() {
        sort();
        for (int i = 0; i < noOFStudents; i++) {
            cout << i + 1 << ": ";
            display(&students[i]);
        }
    }

    void deallocateMemory() {
        for (int i = 0; i < noOFStudents; i++) {
            delete[] students[i].name;
            students[i].name = nullptr;
        }
        delete[] students;
        students = nullptr;
    }
}