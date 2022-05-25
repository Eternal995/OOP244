// Field Width
// cout_width.cpp
// Course Notes: https://ict.senecacollege.ca/~oop244/pages/content/basic.html

 #include <iostream>
 using namespace std;

 int main() {
     int attendance = 27;
     cout << "1234567890" << endl;
     cout.width(10);
     cout << attendance << endl;
     cout << attendance << endl;
	 return 0;
 }