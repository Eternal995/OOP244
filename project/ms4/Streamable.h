/* Citation and Sources...
Final Project Milestone 4
Module: Streamable
Filename: Streamable.h
Version 1.0
Author	Yongda Long
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#ifndef _SDDS_STREAMABLE_H_
#define _SDDS_STREAMABLE_H_

#include <iostream>

namespace sdds {
    class Streamable {
    public:
        virtual std::ostream &write(std::ostream &os) const = 0;
        virtual std::istream &read(std::istream &is) = 0;
        virtual bool conIO(std::ios &ios) const = 0;
        virtual operator bool() const = 0;
        virtual ~Streamable() {}
    };
    std::ostream &operator<<(std::ostream &os, const Streamable &streamable);
    std::istream &operator>>(std::istream &is, Streamable &streamable);
}

#endif // !