// SAMPLE CODE (WEEK 5)
// inline coding style

class Book{
   char m_title[31];
   int  pages;
   
   Book(){ // safe empty state
           strcpy(m_title, ""); pages = 0; }
		   
   Book(const char* s, int num){ strcpy(m_title, s);
                                pages = num; }
								   
   void display() const { // TO-DO }
   
   Book& operator+(const char* title) { //TO-DO }
   
   Book& operator+(int m){ // TO-DO }
};

int main(){

    Book little, goodRead( "C++ Programming", 500)
	
	little.display();
	goodRead.display();
	
	// TO-DO: USE ONE LINE OF CODE TO CHANGE THE TITLE OF THE BOOK (little) TWO TIMES: 
	          "C Programming", "Python for Dummies".
	
	little.display();
	
	// TO-DO: USE ONE LINE OF CODE TO CHANGE THE PAGES OF THE BOOK (goodRead) TWO TIMES: 
	          600, 700.
	
	goodRead.display();
	
	return 0;
}
/*
SAMPLE OUTPUT:
safe empty state!
title: C++ Programming, pages: 500
title: Python for Dummies, pages: 0
title: C++ Programming, pages: 700
*/