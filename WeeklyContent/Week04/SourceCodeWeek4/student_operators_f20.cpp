 // operator overloading in C++
 // 1. operator + (a member function/member operator)
 // 2. operator == (a helper operator)
 //    a) a friend of the class (not recommended)
 //    b) use of queries (i.e. const member functions in the class)
 //
 // updated on 1/27/2021

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

	   Student operator+ (float); // a member operator (a member function)
	                              // adds a new mark to the current object
				                  // returns an OLD COPY of the current object
		
	      /* an alternative design: helper operator and a friend of the class
	            friend Student operator+ ( const Student&, float ) ;
		   */

	    //Student operator+(float[]);

    // a helper operator that is a friend of the class
	//  - equality test on two Student objets
    friend bool operator == ( const Student&, const Student& );           
 };

// a helper operator that uses queries (NOT as a friend of the class)
// bool operator<( const Student&, const Student&);

// operator == (a friend of the class)
//  - test for equality: all the marks are equal
bool operator ==( const Student& one, const Student& two ){

	 bool result;

	 if ( one.counter != two.counter)  // access private data members!
	     result = false;

	 else {
	       result = true;

	       for (int k=0; ((k < one.counter) && (result == true)); k++)
		        if (one.marks[k] != two.marks[k])
			        result = false;    // DO NOT USE break!     
	 }
	 return result;
 }

 // operator overloading: a member operator
 //  - create a copy of the current object
 //  - add a new mark to the current object
 //  - return an OLD COPY of the current object

 Student Student::operator+ (float moreMarks){
 
    Student oldCopy;  // a local object, initialized by the default constructor

    // create a copy of the current object
    oldCopy = *this; 

    // add a new mark to the current object if the array of marks is NOT FULL
    if (counter < MAX){ 
	
	     marks[counter] = moreMarks;
	     (counter)++;
    }
    return oldCopy; // return an old copy of the current object
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

 /* THE CLIENT PROGRAM */
 int main() {

     float scores[] = { 55.5, 65.5, 75.5, 100.0 };

     Student c, d(5678, scores, 4), old;

     // Part 1
     cout << "### C++ Operator Overloading - Member Operators ###" << endl;

     d.display();
     old.display();

     cout << ".......apply the binary operator +" << endl;

     old =  d + 99.5;  // current object: d

     // old = d.operator+( 99.5 )

     d.display();

	 cout << "old copy:" << endl;
     old.display();

     /*
     d + 35.5;
     d.display();
     */

     // Part 2
     cout << "\n### C++ Operator Overloading - Helper Operators ###" << endl;

     c = d;

     if (c==d)      // operator function: operator ==( c, d )
	      cout << "c and d: equal objects" << endl;     //***
	 else cout << "c and d: UNEQUAL OBJECTS" << endl;
     
     if (c==old)
	       cout << "c and old: equal objects" << endl;
     else  cout << "c and old: UNEQUAL OBJECTS" << endl;  //***
  
     return 0;
 }
