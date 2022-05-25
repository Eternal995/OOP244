/*
   istream insertion operatior (>>)
      - the newline character ('\n') is extracted from the input stream

   updated on 5/23/2020
 */
#include <iostream>
using namespace std;

const int size = 3;

int main()
{
   int i, j, num1, num2;
   char s1[31], code;


   for (i=0; i<2; i++) {
       cout << "Enter one integer: ";
      
	cin >> num1;                 // '\n' is NOT left in the input stream

       cout << "num1: " << num1 << endl;
   }

   for ( i=1; i<=2; i++ ) {

	cout << "Enter two integers on one line: ";

	cin >> num1 >> num2;

	cout << " num1: " << num1
	     << " num2: " << num2 << endl;
   }

   // Part 2
   for ( i=1; i<=size; i++ ){
       cout << "\nEnter one character:";

       cin >> code;                       // '\n' is NOT left in cin

       cout << "the character is " << code << endl;
   }

   cout << "\nEnter 3 characters separated by many spaces:" << endl;

   for ( i=1; i<=size; i++ ){
       cin >> code;
       
       cout << "the character is " << code << endl;
   }

   // Part 3   
   for ( j=1; j<=2; j++ ) {

	if ( j==1 )
	     cout << "\n\t1. DO NOT INCLUDE  a blank space in a string\n";
	else cout << "\n\n2. INCLUDE many blank spaces in a string!\n";
       
	for(i=1; i<=size; i++) {
		cout << "\nEnter a short string:";
   
		cin >> s1;
		cout << "You have entered the string:" << s1 << endl;
	}
   }

   return 0;
}









