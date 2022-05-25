// destructor

// C++ class declaration and class implementation in ONE source file
// a better design: a header file (.h) + an implementation file (.cpp)
// matrix: g++ student.cpp OR g++ -std=c++11 student.cpp

/* Concepts
   1. C++ class: a data type
   2. C++ object: an instance of a C++ class; a variable
   3. C++ class = DECLARATIONS (.h) + IMPLEMENATION (.cpp)
      a) declarations of private data members
      b) declarations of public member functions
      c) declarations of constructors and a destructor
      d) implemenation of the member functions, constructros and destructor
   4. C++ object = priavate data members + public member functions

 */
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

/* C++ class declaration (DATA TYPE) 
   - private data members
   - public  member functions 
 */

class Student {
		      /* declarations of PRIVATE data members */
     int  no;
     char grades[14];

     public:         
		     /* declarations of constuctors */
	 Student( );
	 Student( int, const char* );        // a const pointer

		     /* declarations of PUBLIC member functions */
	 void set( int n,  const char * g ); // a const pointer
	 void display() const;               // a const member function

	 ~Student();  // declaration of the destructor
 };

 /* C++ class implementation of member functions */

 /* 2 constructors (the class resolution operator ::) 
     - the objects are initialized properly
     - the default constructor: objects are initialized to be in safe empty states
       (i.e. well-defined states) at the time of creation
  */
 Student::Student() { set( 12345, "AAAA" ); }

 Student::Student(int m, const char * s) { set(m, s); }
 
 Student::~Student() { cout << "...the object will go out of scope, do some clean up: "
			                << no  << ", " << grades << endl;
 }

 /* 2 member functions (the class resolution operaotr ::) */ 
 void Student::set(int n, const char* g){

	  no = n;

	  strcpy( grades, g );

	  // - assumptions
	  //   - what if g is nullptr?
	  //   - what if n is out of range?
 }
 
// a const member function
 void Student::display() const {

	//no += 1000;

	cout << "student number: " 
	     << no << " "  
	     << " grades: " << grades << endl;
 }


int main(){

    Student a, b(9987, "FFF");    // declarations of two C++ objects
				  // the object a is in a safe empty state 
				  // at the time of object creation

    /* a member funciton is called/invoked with an object */
    /* get data from two objects and display them */

    a.display();
    b.display();

    /* store new data into two objects */
    //a.set( 3453, "BBFAC" );
    //b.set( 1111, "CCCCCCF" );

    //a.display();
    //b.display();

    /* object b goes out scope; the desctructor goes into action! */
    /* object a goes out of scope; the destructor goes into action! */
    return 0;
}

