
 // 1. matrix: g++ -std=c++11 -g bugs_valgrind.cpp
 // 2.a matrix: valgrind a.out
 // 2.b READ THE ERROR MESSAGES FROM VALGRIND!
 
 // 3.a matrix: valgrind --leak-check=full a.out
 // 3.b READ THE LINE NUMBERS SHOWN BY VALGRIND!!!
 
 // 4. Explain the errors and fix the errors.
 

 #include <cstring>
 #include <iostream>
 using namespace std;

 int main() {
     int m;
	 char  static_array[] = "C++";
	 char* word = nullptr;        

     m = strlen(static_array);
     word = new char [m+1]; 
	 strcpy(word, static_array);
	 cout << "1. " << word << endl;
	 
	 strcpy(static_array, "WOW");
	 word = new char[m+1];
	 strcpy(word, static_array);
	 cout << "2. " << word << endl;
	 
	 word = nullptr;    
     return 0;
 }
