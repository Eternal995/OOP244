// OBJECTS AND DYNAMIC MEMORY ALLOCATION

// MEMBERWISE COPYING (SHALLOW COPYING):
// command line on matrix: g++ -std=c++11 -g employee_proper.cpp
// *** the Valgrind tool on matrix: valgrind a.out
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
      Employee(const char*, int, double);

      // Note: the default constructor is missing!

      ~Employee();

      //Employee( const Employee & ); // COPY CONSTRUCTOR

      //Employee& operator =( const Employee & );
				  // assignment operator: member operator!
      
      void display();
      void replace( const char *s );   
};

void Employee::replace( const char *s ){
     strcpy( name, s );
}


// dynamic memory allocation and the constructor
Employee::Employee( const char *s, int m, double t ){
   // data members of the current object: name, idnum, salary
   name = new (nothrow) char [strlen(s) + 1];
   
   if ( name != nullptr ) { // C++ 11 standard
	strcpy( name, s );
	idnum = m;
	salary = t;
   }
}

Employee::~Employee(){             
   // debugging!
   cout << "...debug: name: " << name << endl;

   delete [] name;  // a BLOCK of memory!
   name = nullptr;
}

void Employee::display() {
   if (name == nullptr)
       cout << "the object is at a safe empty state" << endl;
   else
      cout << ">>> name: " << name << " id: " << idnum
	       << " salary:$" << salary << endl;
}

int main(){
   Employee young("Bill Gates", 999, 2000.01),
            seneca(young);   // the copy constructor is invoked!
   
   young.display();
   seneca.display();

   cout << "\n\tSIDE EFFECT: young.replace()...\n";

   young.replace( "?x?y?" ); // side effect!
   
   young.display();
   seneca.display();
   cout << "\n??? The END: ANOTHER PROBLEM ???" << endl;

   return 0;   // the destructor goes into action!!!
}
		 
