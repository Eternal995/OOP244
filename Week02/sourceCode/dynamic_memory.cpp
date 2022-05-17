 // Dynamic Memory Allocation in C++
 // - allocate an array of CHARACTERS dynamically (i.e. at run-time)
 // - 3 steps
 
 // matrix: g++ -std=c++11
 // updated on 9/08/2020
 
 #define _CRT_SECURE_NO_WARNINGS
 #include <cstring>
 #include <iostream>
 using namespace std;

 int main() {

     char waste[1000]; // a static array

     /* Part 1 - static memory */

     cout << "Enter an English word (without any blank space): ";
     cin >> waste;

     int n = strlen(waste);

     cout << "The English word contains " << n << " characters."
	  << "\nHow much memory storage is wasted?" << endl;    

     /*Part 2 - Dynamic Memory Allocation */

     int m;
	
     cout << "\n>>> Please enter the number of characters in the English word: ";
     cin >> m;

     // Step 1. Declare a pointer of a given data type.
     char* word = nullptr;        

     // Step 2. Allocate memory storage at run-time.
     word = new char [m+1];    // why m+1, not m?

     // assumption: memory allocation is successful
     // store a string at the memory storage

	  cout << ">>> Please enter the English word: ";
	
	  cin >> word;

	  /* for (int k=0; k<strlen(word); k++)
		cout << word[k] << endl;
	   */        

	 cout << "### You have entered this English word: " << word
	      << "\n### It has " << strlen(word) << " characters." << endl;

     // Step 3. Release the memory storage to avoid MEMORY LEAK!
     delete [] word;   
     word = nullptr;
     
     return 0;
 }
