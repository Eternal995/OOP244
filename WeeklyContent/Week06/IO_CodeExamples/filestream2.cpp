/* Input File Only */

#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std;

/* DOS command line: filestream2 test.dat */
/* Linux command line: a.out test.dat */

int main(int argc, char* argv[]) { // command-line arguments

    cout << "argc: " << argc << endl  
	 << "argv[1]: " << argv[1] << endl;; 

    cout << "...open an input file" << endl;

    ifstream inputFile; // file object

    inputFile.open( argv[1], ios::in );  // file name
					 // open mode: ios::in


    int    num;
    double value;
    char   name[31];

    if ( inputFile.fail() ) {  // query the state of the file stream
			       // (e.g. the input file does not exist)

	 cerr << "Failure in opening a file!" << endl;
	 exit(1);
    }
    else {
	      cout << "...read a record" << endl;
	      // a record has 3 fields: integer, string, double

	      inputFile >> num >> name >> value;    // read data

	      while ( !inputFile.eof() ){ 
			    // EOF: try to read beyond the EOF marker
	       
		 cout << num << "," << name << "," << value << endl;
		 
		 inputFile >> num >> name >> value; // read data
	      }

	      cout << "...close the file" << endl;
	      inputFile.close();
    }

    return 0;
}
