// Input Extraction using getline()
// cin_getline_Notes.cpp
// Course Notes: https://ict.senecacollege.ca/~oop244/pages/content/basic.html

// User Input: cdefghi + \n + jklmn + \t + opqr

 #include <iostream>
 using namespace std;

 int main() {
     char t[8], u[8], v;

     cin.getline(t, 8);       // newline delimiter - accepts up to 7 chars 
			      //    and adds a null byte
     cin.getline(u, 8, '\t'); // tab delimiter - accepts up to 7 chars and
			      //    adds a null byte
     cin.get(v);              // extracts a single character

     cout << "t = " << t << endl;
     cout << "u = " << u << endl;
     cout << "v = " << v << endl;
	 return 0;
 }
