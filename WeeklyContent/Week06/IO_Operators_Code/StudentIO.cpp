
 #include "StudentIO.h"
 #include <cstring>
	
 
  /* implementations of two helper functions 
      - Note: You may omit "std::" if you have included "using namespace std;".
   */  
  std::ostream& operator<< (std::ostream& os, const StudentIO& person) {
  
     person.write(os); // member function call with a StudentIO object
	 
     return os;
  }
  
  std::istream& operator>> (std::istream& is, StudentIO& person) {
  
     person.read(is); // member function call with a StudentIO object
     return is;
  }
	
 /* C++ class implementation */
 
 std::ostream& StudentIO::write(std::ostream& os)const {
 
    os << "number: " << no << ", "
       << "grades: " << grades << std::endl;

    return os;
 }
 
 std::istream& StudentIO::read(std::istream& is) {
 
	// data members of the current object: no, grades
	std::cout << "Enter a studnet number: ";
	is >> no;

	std::cout << "Enter the grades: ";
	is >> grades;

	return is;
 }
 
 StudentIO::StudentIO(int d) { set(d, "AA");  } 
 StudentIO::StudentIO() { set( 12345, "A+A+" ); }
 StudentIO::StudentIO(int m, const char * s) { set(m, s); }
 
 void StudentIO::set(int n, const char* g){
	  no = n;
	  strcpy( grades, g );
 }