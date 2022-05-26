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

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_

namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char *name);
   bool read(int &no);
   bool read(char &grade);
}
#endif // !SDDS_FILE_H_
