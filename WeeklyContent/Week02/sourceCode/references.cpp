/* 1. C++ reference parameters
   2. function overloading (many different functions with the SAME NAME)
   3. a const array parameter: an unmodifiable address of an array 

   updated on 9/08/2019     
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct Item{
   int   qty;
   float price;
};

/* function overloading */
void foo(Item, int );

void foo(Item&);                // C++ reference parameter

float foo(const Item[], int );  // const array parameter

void ref_item(const Item&, int); // const C++ reference parameter

int main(){

    Item one = { 100, 4.56 };

    foo(one, 9999); // passing by value	   
    foo(one);       // passing by reference

    cout << "3. one: " << one.qty << "," << one.price << endl;

    // Part 2
    Item goods[4] = { {123, 4.56}, {456, 2.66}, {789, 9.55}, {809, 6.75} };
    
    int size = 4;

    cout << "the highest price: $" << foo(goods, size) << endl;

    // Part 3
       // error!!!
       //ref_item(goods, 4); // good: an array!

    ref_item(goods[0], 4);  // passing by value
}

void foo(Item copy, int m){  // passing by value

     //copy.qty = -12345;
     cout << "1. m: " << m;
     cout << " quantity: " << copy.qty << ", price: " << copy.price << endl;
}

void foo(Item& item){  // passing by reference

   cout << "2. " << item.qty << "," << item.price << endl;

   item.qty = -11999; // side effect!
		      // use the const qualifier
}


// list: an UNMODIFIABLE address of an array (const)
float foo( const Item list [], int num ){

    int k;
    float highest = 0.0;

    for (k=0; k < num; k++)
	 if ( list[k].price > highest )
	      highest = list[k].price;

    // list[0] = -9999;
    return highest;
}

void ref_item(const Item& refElement, int m){

   
   //refElement.qty += m; // compile-time error

   cout << "4. const referene parameter: "
	<< refElement.qty << endl; 
}
