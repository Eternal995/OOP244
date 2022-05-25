
/* Question: How to return a copy of the current object?
   Answer:    Use the this pointer
   
   updated on 10/06/2020
 */
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

/* C++ class declaration 
   - declarations of private data members
   - declarations of public  member functions: function prototypes 
 */

class Student {
		      /* declarations of private data members */
     int no;
     char grades[14];

     public:         
		     /* declarations of constructors */
	Student( );
	Student( int, const char* );

		     /* declarations of public member functions */
	void set( int n,  const char * g );
	void display() const;

	Student update( const char* );  // return a Student object!
 };

 /* C++ class implementation */
 
 /* The member function updates the grades of the current object 
    and returns an "old copy" of the current object (i.e. old grades).
  */
 Student Student::update( const char* newGrades ){
 
    Student oldCopy;    // a local object

    /* oldCopy.no = no;
       strcpy(oldCopy.grades, grades);
     */

    oldCopy = *this;   // this: a system pointer to the current object
		               // *this: the current object (in the main function)
			     
	
    strcpy(grades, newGrades);     // grades: data member of the current object
    
    /*
      strcpy( (*this).grades, newGrades); // use the this pointer!
      strcpy( this->grades, newGrades );
     */

    return oldCopy; // Question: How about "return *this"?
 }

 Student::Student() { set(0, "???" ); }

 Student::Student(int m, const char * s) { set(m, s); }

 void Student::set(int n, const char* g){

	  // no data validation

	  no = n;

	  strcpy( grades, g );
 }
 
 void Student::display() const {

	cout << setfill('0') << setw(7) 
	     << no << "  "
	     << setfill( 'x' ) << setw(10) << " " 
	     << grades << endl;
 }

int main(void){

    Student a, b(9876, "BBBB"), old(7007, "DDDD");
		
   
    a.display();   // the current object: a
    b.display();   // the current object: b
    old.display(); // the current object: old

    cout << "... 1. update the grades of an object: a" << endl;

    old = a.update( "AAAA" );  // the current object: a   
    a.display();

	cout << "1. old copy>>> ";
    old.display();

    cout << "... 2. update the grades of another object: b" << endl;

    old = b.update("FFFF");   // the current object: b
    b.display();

	cout << "2. old copy>>> ";
    old.display();

    return 0;
}
