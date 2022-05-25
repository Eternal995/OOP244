 // operator overloading in C++
 // 1. operator + (a member function/member operator)
 // 2. operator == (a helper operator)
 //    a) a friend of the class (not recommended)
 //    b) use of queries (i.e. const member functions in the class)
 //
 // updated on 10/06/2020 

 #define _CRT_SECURE_NO_WARNINGS
 #include <cstring>
 #include <iostream>
 #include <iomanip>
 using namespace std;

 // C++ constant declaration
 const int  MAX = 12;

 class Student {

    int no;
    float marks[MAX];
    int counter;

    public:
	   Student();
	   Student( int, const float[], int );

	   void set();
	   void set( int, const float[], int );
	   void display() const;
	   
	   int getCounter() const;           // query used by the helper operator
	   const float* getMarks() const;      // query used by the helper operator
 };

// operator ==
//  - a helper operator that uses queries (NOT as a friend of the class)
//  - test for equality: all the marks are equal
bool operator ==( const Student& one, const Student& two ){

	 bool result;

	 if ( one.getCounter() != two.getCounter() )  // access private data members!
	     result = false;

	 else {
	       result = true;

		   const float* marks_one, *marks_two;
		   
		   marks_one = one.getMarks();
		   marks_two = two.getMarks();
		   
	       for (int k=0; ((k < one.getCounter()) && (result == true)); k++)
		        if (marks_one[k] != marks_two[k])
			        result = false;    // DO NOT USE break!     
	 }
	 return result;
 }

 
 int Student::getCounter() const{
     return counter;
 }
 
 const float* Student::getMarks() const {
    return marks;
 }

 Student::Student() { set(); }         

 Student::Student( int m, const float data[], int sz) {
    set(m, data, sz); 
 }

 void Student::set(int num, const float data[], int size){
 
    no = num;
    counter = size;

    for (int k=0; k<size; k++)
	     marks[k] = data[k];
 }

 void Student::set() {
 
    float data[] = { 88.88, 77.77 };
    set( 10001, data, 2);
 }

 void Student::display() const {

     cout << fixed << setprecision(2)
	      << "* student number: " << no << endl
	      << "*   " << counter << " marks: ";

     for (int i=0; i<counter; i++)
	      cout << marks[i] << " ";
          cout << endl;
 }

 int main() {

     float scores[] = { 55.5, 65.5, 75.5, 100.0 };

     Student c, d(5678, scores, 4), old;

     c = d;

     if (c == d)      // operator function: operator ==( c, d )
	      cout << "c and d: equal objects" << endl;     //***
	 else cout << "c and d: UNEQUAL OBJECTS" << endl;
	 
	 if (old == d)      // operator function: operator ==( c, d )
	      cout << "old and d: equal objects" << endl;     //***
	 else cout << "old and d: UNEQUAL OBJECTS" << endl;
     
     return 0;
 }
