 // operator overloading in C++
 // 1. operator + (a member function/member operator)
 // - inspired by student questions on Feb. 1, 2021 (OOP244NII)
 //   - add multiple student marks!

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

	   //Student operator+ ( float ); // a member operator (a member function)
	                                // adds a new mark to the current object
				                    // returns an old copy of the current object
									
	   int operator+ (float []);
	   
	   Student& operator+(float);
	               
 };

 int Student::operator+(float list[]){
	 bool done=false;
	 int  counterOld;
	 
	 counterOld = counter;
	 
	 for(int k=0; k<MAX && !done; k++)
	     if ( (list[k] == 0) || counter == MAX)
		       done = true;
		 else (*this) + list[k];   // REUSE operator+ (float)
		
     return (counter - counterOld); // number of new marks added
	 
 }

 // operator overloading: a member operator
 //  - add a new mark to the current object
 //  - return a reference to the current object

 Student& Student::operator+ ( float moreMarks ){

    // add a new mark to the current object if the array of marks is NOT FULL
    if (counter < MAX){ 
	     marks[counter] = moreMarks;
	     (counter)++;
    }
	
    return *this; 
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

     d.display();
     old.display();

     cout << ".......add several student marks" << endl;

           d + 99.5;  // current object: d
     old = d + 35.5;
	 
     d.display();
     old.display();
	 
	 // Part 2
	 cout << "Part 2:" << endl;

	 c + 65.5 + 75.5 + 85.5;
	                   // c.operator+(65.5).operator+(75.5).operator+(85.5)
	 c.display();      // the state of c: 4+3 marks

	 // Part 3
	 float listOfMarks[MAX] = {0};
	 
	 listOfMarks[0] = 92.5;
	 listOfMarks[1] = 72.5;
	 
	 cout << "Part 3:" << endl;
	 c. display();     // the state of c: 2 marks
	 
	 c + listOfMarks;  // c.operator+(listOfMarks);
	 
	 c.display();      // the state of c: 2+2 marks
     return 0;
 }
