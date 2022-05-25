// data type validation

#include <iostream>
using namespace std;

int main(void) {

    double x;
    int    ok;

    for (int k=1; k<=2; k++){
       do {
	  ok = 1;

	  cout << "Pleae enter a floating-point number: ";

	  cin >> x; // What if the user has entered 'A'?

	  /* data type validation */
	  if ( cin.fail() != 0 ) {

	     ok = 0;   // NOT ok

	     cout << "#error: invalid data format!\n";

	     cin.clear();              // reset cin from the failure state
	     cin.ignore(2000, '\n');   // remove the data left in the
				     // input stream
	  }
       } while ( !ok );

       cout << "x = " << x << endl;

    }// end for

    cout << "Goodbye!" << endl;

    return 0;
}
