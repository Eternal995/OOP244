
/* a C++ module
     - a header file: student.h
     - an implementation file: student.cpp
   a main module (a client)
     - student_client.cpp
   matrix command
     g++ -std=c++11 student_client.cpp student.cpp
 */
 
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

#include "student.h"
#include <iostream>
using namespace std;

// a client program 
int main(){

    Student a, b(9987, "AAAAA");   // data type; two variables/objects

    a.display();  // a: the current object; invocation of a public member function
    b.display();  // b: the current object
	              // what if constructors are missing?
				  
    cout << "............" << endl;
    a.set( 3453, "BBFAC" );
    b.set( 1111, "CCAAFFDD" );

    a.display();
    b.display();
	
    /* Part 2 - Tests on data validation. */
    cout << endl << "Part 2 - Data Validation" << endl;

    Student x(-123, "FFF"), y(777, nullptr);

    x.display();
    y.display();
    return 0;
}

