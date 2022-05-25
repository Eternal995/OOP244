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
 
// C++ class declaration (student.h)
// C++ class implementation (student.cpp)

class Student {
     /* declarations of PRIVATE data members */
     int  no;
     char grades[14];

     public:         
     /* declarations of constructors */
	 Student( );                        // an object will be initialized to a safe empty state
	                                    // (i.e. a well-defined state)
	 Student( int, const char* );       // an object will be initialized properly

	 /* declarationS of PUBLIC member functions */
	 void set( int n,  const char * g );  // setter (mutator); a const pointer
	 void display() const;                // getter (query); a const member function
	
};  // BE CAREFUL!

