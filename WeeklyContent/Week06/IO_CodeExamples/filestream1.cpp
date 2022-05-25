/* Output File Only */

#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 5

/* DOS command line: filestream1 test.dat */
/* Linux command line: a.out test.dat */

int main(int argc, char* argv[]) {

    ofstream outputFile;

    outputFile.open( argv[1], ios::out );  // file name
					   // open mode:
					   //    ios::out, ios::app
					   //    (write)   (append)

    int num[MAX] =       { 100, 200, 300, 400, 500 };
    const char* s[MAX] = { "John", "Peter", "Mark", "Matthew", "Jos" };
    double v[MAX] =      { 1.11, 2.22, 3.33, 4.44, 5.55 };

    if ( outputFile.fail() ) {  // query the state of the file stream
				// (e.g. argv[1] is an empty string)

	 cerr << "Failure in opening a file" << endl;
	 exit(1);
    }
    else {
	   for (int k=0; k<MAX; k++){

		cout << "... writing a record to the file\n";

		outputFile << num[k] << " " << s[k] << " "
			   << v[k]   << endl;
	   }
	   outputFile.close();  // close the file stream
    }

    return 0;
}
