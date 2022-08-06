/* Citation and Sources...
Final Project Milestone 5
Module: LibApp
Filename: LibApp.cpp
Version 1.0
Author	Yongda Long
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#include "LibApp.h"

#include <cstring>
#include <fstream>
#include <iomanip>

#include "Book.h"
#include "Menu.h"
#include "PublicationSelector.h"
#include "Utils.h"

using namespace std;

namespace sdds {
    LibApp::LibApp(const char* file)
        : m_mainMenu("Seneca Library Application"),
          m_exitMenu("Changes have been made to the data, what would you like to do?"),
          m_type("Choose the type of publication:") {
        m_changed = false;
        m_mainMenu << "Add New Publication"
                   << "Remove Publication"
                   << "Checkout publication from library"
                   << "Return publication to library";
        m_exitMenu << "Save changes and exit"
                   << "Cancel and go back to the main menu";
        m_type << "Book"
               << "Publication";
        strcpy(m_file, file);
        load();
    }

    LibApp::~LibApp() {
        for (int i = 0; i < m_numLoaded; i++) {
            delete m_pub[i];
            m_pub[i] = nullptr;
        }
    }

    bool LibApp::confirm(const char* message) const {
        Menu menu{message};
        menu << "Yes";
        return (menu.run() == 1);
    }

    void LibApp::load() {
        cout << "Loading Data" << endl;
        m_numLoaded = 0;
        ifstream infile(m_file);
        char type;
        for (int i = 0; infile; i++) {
            infile >> type;
            infile.ignore();
            if (infile) {
                if (type == 'P')
                    m_pub[i] = new Publication;
                else if (type == 'B')
                    m_pub[i] = new Book;
                if (m_pub[i]) {
                    infile >> *m_pub[i];
                    m_numLoaded++;
                }
            }
        }

        m_lastRef = m_pub[m_numLoaded - 1]->getRef();
    }

    void LibApp::save() const {
        cout << "Saving Data" << endl;
        ofstream outfile(m_file);
        for (int i = 0; i < m_numLoaded; i++) {
            if (m_pub[i]->getRef() != 0)
                outfile << *m_pub[i] << endl;
        }
    }

    int LibApp::search(int mode) const {
        char type = 'X';
        int ref = 0;

        switch (m_type.run()) {
        case 1:
            type = 'B';
            break;
        case 2:
            type = 'P';
            break;
        case 0:
            cout << "Aborted!" << endl;
            break;
        }

        if (type == 'B' || type == 'P') {
            char title[SDDS_TITLE_SEARCH];
            cout << "Publication Title: ";
            cin.clear();
            cin.ignore(2000, '\n');
            cin.getline(title, SDDS_TITLE_SEARCH);

            PublicationSelector ps("Select one of the following found matches:", SDDS_DEFAULT_PAGE_SIZE);
            for (int i = 0; i < m_numLoaded; i++) {
                if (m_pub[i]->type() == type && m_pub[i]->getRef() > 0 && *m_pub[i] == title) {
                    if (mode == SDDS_SEARCH_ALL || (mode == SDDS_SEARCH_AVAILABLE && !m_pub[i]->onLoan()) || (mode == SDDS_SEARCH_CHECKOUT && m_pub[i]->onLoan())) {
                        ps << m_pub[i];
                    }
                }
            }

            if (ps) {
                ps.sort();
                ref = ps.run();
                if (ref > 0) {
                    cout << *getPub(ref) << endl;
                } else {
                    cout << "Aborted!" << endl;
                }
            } else {
                cout << "No matches found!" << endl;
            }
        }

        return ref;
    }

    Publication* LibApp::getPub(int libRef) const {
        Publication* pub = nullptr;
        for (int i = 0; i < m_numLoaded && (libRef > 0) && !pub; i++) {
            if (m_pub[i]->getRef() == libRef) {
                pub = m_pub[i];
            }
        }

        return pub;
    }

    void LibApp::newPublication() {
        if (m_numLoaded == SDDS_LIBRARY_CAPACITY) {
            cout << "Library is at its maximum capacity!" << endl;
            return;
        }

        cout << "Adding new publication to the library" << endl;

        char type = 'X';
        Publication* pub = nullptr;

        switch (m_type.run()) {
        case 1:
            type = 'B';
            pub = new Book;
            break;
        case 2:
            type = 'P';
            pub = new Publication;
            break;
        case 0:
            break;
        }

        if (type == 'X') {
            cout << "Aborted!" << endl;
            return;
        }

        cin.clear();
        cin.ignore(2000, '\n');
        cin >> *pub;
        if (!cin) {
            cout << "Aborted!" << endl;
            cin.clear();
            cin.ignore(2000, '\n');
            delete pub;
            return;
        }

        if (!confirm("Add this publication to the library?")) {
            cout << "Aborted!" << endl;
            delete pub;
            return;
        }

        if (*pub) {
            m_pub[m_numLoaded] = pub;
            m_pub[m_numLoaded]->setRef(++m_lastRef);
            m_numLoaded++;
            m_changed = true;
            cout << "Publication added" << endl;
        } else {
            cout << "Failed to add publication!" << endl;
            delete pub;
        }
    }

    void LibApp::removePublication() {
        cout << "Removing publication from the library" << endl;

        int ref = search(SDDS_SEARCH_ALL);

        if (ref <= 0) {
            cout << "Aborted!" << endl;
            return;
        }

        if (!confirm("Remove this publication from the library?")) {
            cout << "Aborted!" << endl;
            return;
        }

        getPub(ref)->setRef(0);
        m_changed = true;
        cout << "Publication removed" << endl;
    }

    void LibApp::checkOutPub() {
        cout << "Checkout publication from the library" << endl;

        int ref = search(SDDS_SEARCH_AVAILABLE);

        if (ref <= 0) {
            // cout << "Aborted!" << endl;
            return;
        }

        if (!confirm("Check out publication?")) {
            cout << "Aborted!" << endl;
            return;
        }

        int member = inputMemberNo();
        getPub(ref)->set(member);
        m_changed = true;
        cout << "Publication checked out" << endl;
    }

    void LibApp::returnPub() {
        cout << "Return publication to the library" << endl;

        int ref = search(SDDS_SEARCH_CHECKOUT);

        if (ref <= 0) {
            cout << "Aborted!" << endl;
            return;
        }

        if (!confirm("Return Publication?")) {
            cout << "Aborted!" << endl;
            return;
        }

        Date today;
        int date = today - getPub(ref)->checkoutDate();
        if (date > SDDS_MAX_LOAN_DAYS) {
            double penalty = (double)date * 0.5;
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << "Please pay $" << penalty << " penalty for being " << date << " days late!" << endl;
        }
        getPub(ref)->set(0);
        m_changed = true;
        cout << "Publication returned" << endl;
    }

    void LibApp::run() {
        unsigned int selection = 1;
        while (selection) {
            selection = m_mainMenu.run();
            switch (selection) {
            case 1:
                newPublication();
                break;
            case 2:
                removePublication();
                break;
            case 3:
                checkOutPub();
                break;
            case 4:
                returnPub();
                break;
            case 0:
                if (m_changed) {
                    unsigned int exitCode = m_exitMenu.run();
                    if (exitCode == 1) {
                        save();
                        break;
                    } else if (exitCode == 2) {
                        selection = 1;
                        break;
                    } else {
                        if (confirm("This will discard all the changes are you sure?")) {
                            break;
                        } else {
                            save();
                            break;
                        }
                    }
                }
            }
            cout << endl;
        }
        cout << "-------------------------------------------" << endl;
        cout << "Thanks for using Seneca Library Application" << endl;
    }
}