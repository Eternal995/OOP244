// Precision
// cout_precison.cpp
// Course Notes: https://ict.senecacollege.ca/~oop244/pages/content/basic.html

 #include <iostream>
 using namespace std;

 int main() {
     double pi = 3.141592653;

     cout << "1234567890" << endl;
     cout.setf(ios::fixed);    // fixed format
     cout.width(10);           // column width
     cout.precision(2);        // precisin control
 
     cout << pi << endl;
 }
