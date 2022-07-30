/* Citation and Sources...
Final Project Milestone 5
Module: Streamable
Filename: Streamable.cpp
Version 1.0
Author	Yongda Long
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#include "Streamable.h"

namespace sdds {
    std::ostream &operator<<(std::ostream &os, const Streamable &streamable) {
        if (streamable)
            streamable.write(os);
        return os;
    }

    std::istream &operator>>(std::istream &is, Streamable &streamable) {
        return streamable.read(is);
    }
}