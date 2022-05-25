// Left Justified
// cout_left.cpp
// Course Notes: https://ict.senecacollege.ca/~oop244/pages/content/basic.html

 #include <iostream>
 using namespace std;

 int main() {
     double pi = 3.141592653;

     cout << "1234567890" << endl;
     cout.width(10);
     cout.fill('*');       // fill the remaining spaces with '*'

     cout.setf(ios::left);
     cout << pi << endl;
	 
     // unsetf(ios::left)
     cout.unsetf(ios::left);
     cout.width(10);
     cout << pi << endl;
     return 0;
 }
