// Fixed Format
// cout_fixed.cpp
// Course Notes: https://ict.senecacollege.ca/~oop244/pages/content/basic.html

 #include <iostream>
 using namespace std;

 int main() {
     double pi = 3.141592653;
     
     cout << "1234567890" << endl;
     cout.width(10);
     cout << pi << endl;

     cout.width(10);
     cout.setf(ios::fixed); // dispaly a number in a FIXED FORMAT
     cout << pi << endl;
	 return 0;
 }
