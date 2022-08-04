/*
*****************************************************************************
Full Name : Yongda Long
Student ID# : 172800211
Email : ylong9@myseneca.ca
Section : OOP244NGG
Date : August 4, 2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_TEMPLATEFUNCTIONS_H_
#define SDDS_TEMPLATEFUNCTIONS_H_

#include <iostream>

#include "Collection.h"

namespace sdds {
    // Find with 3 parameters
    // overload of operator == is needed in this function
    template <typename t1, typename t2>
    bool find(t1 *array, t2 key, int index) {
        return array[index] == key;
    }

    // Find with 4 parameters
    // overload of operator == is needed in this function
    template <typename t1, typename t2, typename t3>
    int find(t1 *array, t2 key1, t3 key2, int number) {
        for (int i = 0; i < number; i++) {
            if (array[i] == key1 && array[i] == key2)
                return i;
        }
        return -1;
    }

    // Insertion operator
    // overload of operator[i] and member function size() of the collection template is needed in this function
    template <typename t>
    std::ostream &operator<<(std::ostream &os, Collection<t> &collection) {
        for (int i = 0; i < collection.size(); i++) {
            os << collection[i] << std::endl;
        }

        return os;
    }

    // Load Collection
    // overload of operator+= of the Collection template is needed in this function
    template <typename t>
    const Collection<t> &loadCollection(Collection<t> &collection, t object) {
        collection += object;
        return collection;
    }
}

#endif  // !SDDS_SEARCH_H_
