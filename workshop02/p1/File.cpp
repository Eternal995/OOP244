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
#include <cstdio>
#include "File.h"

namespace sdds {

    FILE *fptr;

    bool openFile(const char *filename) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    void closeFile() {
        if (fptr)
            fclose(fptr);
    }

    bool read(char *name) {
        return (fscanf(fptr, "%[^,],", name) == 1);
    }

    bool read(int &no) {
        return (fscanf(fptr, "%d,", &no) == 1);
    }

    bool read(char &grade) {
        return (fscanf(fptr, "%c\n", &grade) == 1);
    }
}