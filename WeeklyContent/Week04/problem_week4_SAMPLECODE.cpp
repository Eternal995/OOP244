
// Complete the following C++ program.

#include <cstring>
#include <iostream>
using namespace std;

const int MAX=10, LEN=20;

struct Person{
   char name[LEN+1];
   int  age;
};

class Room{
   Person persons[MAX];     // persons in a room
   int    numberOfPeople;   // number of people in a room
   
   public:
   Room();
   Room(int q, Person persons[]);
   void set(Person persons[], int num); 
   void display() const;
   ~Room();
};

int main(){
    Person students[] = { {"John Doe", 35}, {"Mary Ryen", 65} };
	int size = 2;
	
    // TO-DO
	
    return 0;
}

