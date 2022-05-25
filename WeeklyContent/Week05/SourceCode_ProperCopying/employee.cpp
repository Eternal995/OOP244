// C++ Classes with (Dynamically Allocated) Resources
// - an object uses resources outside its own memory space
// - a pointer, constructors (new), and destructor (delete [])

// - command line on matrix: g++ -std=c++11 -g employee.cpp
// - the valgrind tool on matrix: valgrind a.out

// updated on 2/03/2021

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;

class Employee {

   char*   name;      // a pointer: NO MEMORY HAS BEEN ALLOCATED!
   int    idnum;
   double salary;

   public:
      Employee(const char* = "Dr. Oz", int=90009, double=5555.55); // default parameters

      ~Employee();   // destructor

      void display() const;
};


int main(){
   Employee e1("Bill Gates", 12345, 9999.99),
	        e2, e3("John Doe"), e4(nullptr, -1, -2345);
  
   e1.display();
   e2.display();  
   e3.display(); 
  
   // 3 objects will go out of scope; in what order?
   return 0;
}

// constructor: allocate memory storage (i.e. dynamic memory allocation)
Employee::Employee(const char * s, int m, double t) {
   
   // data members of the current object: name, idnum, salary
  
   if ((s == nullptr) || (m<=0) || (t<0)){

	// a safe empty state
	name = nullptr;
	idnum = 0;
	salary = 0.0;
   }
   else { 
	 name = new (nothrow) char[ strlen(s)+1 ]; // name could be set to nullptr

	 if ( name != nullptr ){ // C++11 standard
	      strcpy(name, s);
	      idnum = m;
	      salary = t;
	 }
	 else{ // a safe empty state
	       idnum = 0;
	       salary = 0.0;
	 }
   }
   /*cout << "... constructor: allocate memory for the data member: ["
	<< name << "]" << endl;
    */
}

// clean-up: deallocate the memory storage!
Employee::~Employee() {

      cout << "... destructor: release the memory allocated for the data member: ["
	   << name << "]" << endl;

      delete [] name;
      name = nullptr;
}

void Employee::display() const
{
   if (name == nullptr)
	   cout << "*** The object is in a safe empty state!" << endl;

   else cout << "*** employee name: " << name << ", id:" << idnum
	         << ", salary:$ " << salary << endl;
}












