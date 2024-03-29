/* Citation and Sources...
Final Project Milestone 5
Module: Lib
Filename: Lib.h
Version 1.0
Author	Yongda Long
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#ifndef _SDDS_LIB_H_
#define _SDDS_LIB_H_

namespace sdds {
    const int SDDS_MAX_LOAN_DAYS = 15;
    // maximum number of day a publication can be borrowed with no penalty
    const int SDDS_TITLE_WIDTH = 30;
    // The width in which the title of a publication should be printed on the console
    const int SDDS_AUTHOR_WIDTH = 15;
    // The width in which the author name of a book should be printed on the console
    const int SDDS_SHELF_ID_LEN = 4;
    // The width in which the shelf id of a publication should be printed on the console
    const int SDDS_LIBRARY_CAPACITY = 333;
    // Maximum number of publications the library can hold.

    const int SDDS_FILE_NAME = 256;
    // Maximum number of characters for data file name

    const int SDDS_SEARCH_ALL = 1;
    const int SDDS_SEARCH_CHECKOUT = 2;
    const int SDDS_SEARCH_AVAILABLE = 3;
    // 3 different modes for search member function of LibApp Class

    const int SDDS_DEFAULT_PAGE_SIZE = 15;
    // Default page size for selector menu
    const int SDDS_TITLE_SEARCH = 256;
    // Maximum number of characters for searching title
}

#endif // !