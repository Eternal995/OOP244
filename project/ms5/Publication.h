/* Citation and Sources...
Final Project Milestone 5
Module: Publication
Filename: Publication.h
Version 1.0
Author	Yongda Long
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#ifndef _SDDS_PUBLICATION_H_
#define _SDDS_PUBLICATION_H_

#include "Date.h"
#include "Lib.h"
#include "Streamable.h"

namespace sdds {
    class Publication : public Streamable {
        char *m_title;
        char m_shelfID[SDDS_SHELF_ID_LEN + 1];
        int m_membership;
        int m_libRef;
        Date m_date;

      public:
        Publication();
        Publication(const Publication &source);
        Publication &operator=(const Publication &source);
        virtual ~Publication();

        virtual void set(int member_id);
        void setRef(int value);
        void resetDate();

        virtual char type() const;
        bool onLoan() const;
        Date checkoutDate() const;
        bool operator==(const char *title) const;
        operator const char *() const;
        int getRef() const;
        bool conIO(std::ios &io) const;
        std::ostream &write(std::ostream &os) const;
        std::istream &read(std::istream &is);
        operator bool() const;
    };
}

#endif  // !