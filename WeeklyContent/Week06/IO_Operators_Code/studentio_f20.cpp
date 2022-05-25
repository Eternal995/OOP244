
// C++ class declaration and class implementation in ONE source file
// a better design: a header file (.h) + an implementation file (.cpp)

#include "StudentIO.h"
	 
/* 1. the client code
      - use of the overloaded ostream insertion operator and the istream extraction operator
	  - use of the StudentIO class

   Updated on 10/21/2020 
 */

int main(){
    StudentIO a, b(9987, "AAAAA"), c;
	
	// Part 1
    std::cout << a;
    std::cout << b;
	
    // Part 2
    std::cout << "Part 2\n";
    
    std::cin >> c;
    
    std::cout << c;

    return 0;
}










