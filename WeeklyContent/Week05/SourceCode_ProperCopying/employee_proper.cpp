// OBJECTS AND DYNAMIC MEMORY ALLOCATION
// memberwise copying (shallow copying)
// proper copying (deep copying):
// - overload 
//   a) the copy constructor AND
//   b) the assignment operator (operator =)

// What if operator = does NOT return a reference to the object?
// a) dependent on the copy constructor 
// b) no chaining

// command line on matrix: g++ -std=c++0x -g employee_proper.cpp
// updated on 2/03/2021

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std; 

class Employee {
   char * name;      // NO memory has been allocated!
   int    idnum;
   double salary;

   void init( int, const char*);  // private member function!

   public:
      Employee(const char* = "Dr. Oz", int=90009, double=5555.55);

      ~Employee();

      Employee(const Employee&); // COPY CONSTRUCTOR

      Employee& operator=(const Employee &);
				                 // the copy assignment operator: a member operator!
      void display() const;
      void replace( const char *s );   
};

void Employee::replace( const char *s ) {
     int len = strlen(name);

     strncpy( name, s, len ); // reuse the memory storage
     name[len] = '\0';
}

// private member function: allocate memory for storing a copy of a string
// - accessed by the current object
void Employee::init( int size, const char *s) {
     
     name = new (nothrow) char[ size+1 ];
     if ( name != nullptr )
	      strcpy( name, s );
}

// Overload the copy assignment operator.
// - the return type is Employee& (a C++ reference)!
// - 3 steps

Employee& Employee::operator=( const Employee& rhs ) {

   // data members of the current object (LHS): name, idnum, salary
   if( &rhs != this ){       // 1. check for self-assignment: x=x;

		//cout << "\t =: release memory for [" << name << "]" << endl;
	  if (name != nullptr)
	      delete [] name;    // 2. release current memory storage

		//cout << "\t =: allocate new memory storage\n";

	  // 3. request memory storage and copy the data
      name =  new (nothrow) char [strlen(rhs.name) + 1];
	              /* init( strlen( rhs.name ), rhs.name ); */
	
	  // 4. COPY THE DATA from rhs to the current object
      if ( name!= nullptr ){ 
	       strcpy( name, rhs.name);
	       idnum = rhs.idnum;
	       salary = rhs.salary;
	  }
   }
   return *this;  // the current object!
}

// Overload the COPY CONSTRUCTOR.
// - no return type!
// - 2 steps
// - two lines of code!

Employee::Employee( const Employee& source ){
          //cout << "\t inside the copy constructor" << endl;

    name = nullptr; // very important!!! (error: UNINITIALIZED pointer)
    *this = source; // REUSE the copy assignment operator!
  
   /* implemenation #2
      name = nullptr;
      init( strlen(source.name), source.name); 

      if (name != nullptr){
	      idnum = source.idnum;
	      salary = source.salary;
      }   
    */
   
   /* implementation #3

   // 1. dynamic memory allocation!
   name =  new (nothrow) char [strlen(source.name) + 1];

   // 2. copy the data
   if ( name != nullptr ){ // C++ 11 standard
	    strcpy(name, source.name);
	    idnum = source.idnum;
	    salary = source.salary;
   }
   */
	       //cout << "\t leaving the copy constructor..." << endl;
}

// a three-argument constructor 
Employee::Employee( const char *s, int m, double t )
{
   // data members of the current object: name, idnum, salary

   // no validation on input parameters

   // allocate memory to store a sting
   name = nullptr;
   init( strlen(s), s ); 

   // initialize other data members
   if (name != nullptr){
       idnum = m;
       salary = t;
   }

/*
   name = new (nothrow) char [strlen(s) + 1];
   
   if ( name != nullptr ) { // C++ 11 standard
	strcpy( name, s );
	idnum = m;
	salary = t;
   }
 */
	//cout << "...constructor: allocate memory for the data member ["
	//     << name << " ] " << endl;
}

Employee::~Employee()
{
	cout << "...destructor: release the memory allocated for the data member ["
	     << name << "]" << endl;

	delete [] name;  // a BLOCK of memory!  
}

void Employee::display() const
{
   if (name == nullptr)
       cout << "the object is at a safe empty state" << endl;
   else
       cout << "employee name: " << name << " id: " << idnum
	    << " salary:$" << salary << endl;
}

// THE CLIENT PROGRAM
int main(){
   cout << "Testing the copy assignment operator =..."
	    << endl;

   Employee old("David Senior", 111, 1000.01),
	        young("Shomari Junior", 999, 2000.02);
   
   old.display();  young.display();

   /* Part 1: the copy assignment operator (=) */
   cout << "\tDeep Copying/Proper Copying: old = young;" << endl;

   old = young; // 1. the copy assignment operator

   cout << "\n\tmain(): old.display(); young.display()..." << endl;
   old.display();
   young.display();

   cout << "\n\tmain(): old.replace()...\n";
   old.replace( "!@#$%" );  // possible side effect

   old.display();
   young.display();

   /* Part 2: the copy constructor */
   Employee seneca(young); // the copy constructor is invoked!
                           // Employee seneca=young;
			    
   cout << "Part 2: Testing the copy construtor...\n";
   young.display();
   seneca.display();

   cout << "\n--- The END ---" << endl;
   return 0;    // the destructor goes into action!
}
