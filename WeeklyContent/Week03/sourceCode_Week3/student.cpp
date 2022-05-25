/* Concepts
   1. C++ class: a data type
   2. C++ object: an instance of a C++ class; a variable
   3. C++ class = DECLARATIONS (.h) + IMPLEMENATION DETAILS(.cpp)
      a) declarations of private data members
      b) declarations of public member functions
      c) declarations of constructors and a destructor
      d) implementation details of the member functions, constructors and destructor
   4. C++ object = private data members + public member functions
   5. encapsulation: a) a well-defined interface for client programs
		             b) implementation details are hidden from client programs

   updated on 9/29/2020
 */
 
// C++ class implementation (student.cpp)
 #define _CRT_SECURE_NO_WARNINGS
 #include "student.h"
 #include <iomanip>
 #include <iostream>
 #include <cstring>
 using namespace std;

 /* C++ class implementation
     - the class resolution operator (::)
  */ 
 
 // The default constructor initializes an object to have a SAFE EMPTY STATE.
 Student::Student() { set( 0, "ABCD" ); }

 // The two-argument constructor use input parameters to initialize an object.
 Student::Student(int m, const char * s) { set(m, s); }
 
 void Student::set(int n, const char* g){

	  // data validation
	  if (n > 0)
	       no = n; // store the value of n into the data member(no) in an object!
	  else no = 0; // default value for a safe empty state

	  if (g != nullptr)
	       strcpy( grades, g );      // What if g has 20 characters?
				                     //  - use strncpy!
	  else strcpy( grades, "ABCD" ); // default value for a safe empty state
 }
 
 void Student::display() const { // Warning: Do not omit "const" here!
 
      if ((no == 0) || (strcmp(grades, "ABCD") == 0))
	       cout << "SAFE EMTPY STATE" << endl;
      else
	       cout << setfill('0') << setw(7) << no
		        << setfill('#') << setw(14) << grades << endl;     	
		           // IO manipulators: setfill(), setw()
	  //no = -12345;
 }



