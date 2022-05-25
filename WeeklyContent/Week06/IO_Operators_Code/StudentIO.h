
/* C++ class declaration 
    - private data members
    - public  member functions

   Overload the ostream insertion operator(<<) and 
   the istream extraction operator (>>).
    - helper functions/operators

   Updated on 10/21/2020 
 */

#include <iostream>

class StudentIO {
		      /* declarations of data members */
     int no;
     char grades[14];

     public:         
		     /* declarations of constructors */
	StudentIO( );
	StudentIO( int, const char* );
	StudentIO(int);
		     /* declarations of member functions */
	void set( int n,  const char * g );
	
	/* std: namespace for istream and ostream classes, given by the C++ language */
	std::istream& read(std::istream& is);
	std::ostream& write(std::ostream& os)const;  // const member function that cannot modify the current object!
 };
 
 /* two helper functions: declared outside the class */
 std::ostream& operator<< (std::ostream& os, const StudentIO& person);
 std::istream& operator>> (std::istream& is, StudentIO& person);
 
 