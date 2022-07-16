/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: LibApp.cpp
Version 1.0
Author	Yongda Long
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/

#include "LibApp.h"
#include "Menu.h"
#include "Utils.h"
#include <cstring>
#include <iomanip>

using namespace std;

namespace sdds {
    LibApp::LibApp() {
        m_changed = false;
        m_mainMenu << "Add New Publication"
                   << "Remove Publication"
                   << "Checkout publication from library"
                   << "Return publication to library";
        m_exitMenu << "Save changes and exit"
                   << "Cancel and go back to the main menu";
        load();
    }

    bool LibApp::confirm(const char *message) const {
        Menu menu{message};
        menu << "Yes";
        return (menu.run() == 1);
    }

    void LibApp::load() const {
        cout << "Loading Data" << endl;
    }

    void LibApp::save() const {
        cout << "Saving Data" << endl;
    }

    void LibApp::search() const {
        cout << "Searching for publication" << endl;
    }

    void LibApp::returnPub() {
        search();
        cout << "Returning publication" << endl;
        cout << "Publication returned" << endl;
        m_changed = true;
    }

    void LibApp::newPublication() {
        cout << "Adding new publication to library" << endl;
        if (confirm("Add this publication to library?")) {
            m_changed = true;
            cout << "Publication added" << endl;
        }
    }

    void LibApp::removePublication() {
        cout << "Removing publication from library" << endl;
        search();
        if (confirm("Remove this publication from the library?")) {
            m_changed = true;
            cout << "Publication removed" << endl;
        }
    }

    void LibApp::checkOutPub() {
        search();
        if (confirm("Check out publication?")) {
            m_changed = true;
            cout << "Publication checked out" << endl;
        }
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