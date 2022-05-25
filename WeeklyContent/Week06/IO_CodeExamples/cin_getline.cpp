/* Use of cin.getline() to avoid memory buffer overflow
      - Whitespace characters will be allowed.

      - The user may enter a) 1-10 characters, and 
			   b) more than 10 characters.
*/

/* test cases:
   1)A b c I'm?
   2)1 2 3 4 5......I'm tired??????xxxxxxxxxxyyyyyyyyyyyyyyyyzzzzzz
 */

#include <iostream>
using namespace std;

int main(void)
{
 char name[11];

 for ( int i=0; i < 3; i++ ) {

      cout << "Enter a line of characters(max:10):" << endl;

      cin.getline(name, 11, '\n');   // '\n': a delimiter
				     // '\n' is NOT left in the input stream
				     // a default delimiter

      cout << "\tYou have entered:" << name << endl;

      /* clear the buffer if it is not empty */
      if (cin.fail() == 1){         // check the state of the cin object
	  cin.clear();              // reset the state of the cin object
	  cin.ignore(2000, '\n');   // ignore/discard characters
      }
 }
 return 0;
}
