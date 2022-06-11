/*
*****************************************************************************
Full Name : Yongda Long
Student ID# : 172800211
Email : ylong9@myseneca.ca
Section : OOP244NGG
Date : June 11, 2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "CleanerBot.h"
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

namespace sdds {
    CleanerBot::CleanerBot() {
        setEmpty();
    }

    CleanerBot::CleanerBot(const char *location, double battery, int brush, bool active) {
        if (location == nullptr || strlen(location) == 0) {
            location = nullptr;
        } else {
            bot_location = new char[strlen(location) + 1];
            strcpy(bot_location, location);
        }

        bot_battery = battery;
        bot_brush = brush;
        bot_active = active;
    }

    CleanerBot::~CleanerBot() {
        if (bot_location != nullptr) {
            delete[] bot_location;
            bot_location = nullptr;
        }
    }

    void CleanerBot::setEmpty() {
        bot_location = nullptr;
        bot_battery = 0;
        bot_brush = 0;
        bot_active = false;
    }

    void CleanerBot::set(const char *location, double battery, int brush, bool active) {
        setLocation(location);
        bot_battery = battery;
        bot_brush = brush;
        bot_active = active;
    }

    void CleanerBot::setLocation(const char *location) {
        if (bot_location != nullptr) {
            delete[] bot_location;
        }

        if (location == nullptr || strlen(location) == 0) {
            bot_location = nullptr;
        } else {
            bot_location = new char[strlen(location) + 1];
            strcpy(bot_location, location);
        }
    }

    void CleanerBot::setActive(bool active) {
        bot_active = active;
    }

    char *CleanerBot::getLocation() const {
        return bot_location;
    }

    double CleanerBot::getBattery() const {
        return bot_battery;
    }

    int CleanerBot::getBrush() const {
        return bot_brush;
    }

    bool CleanerBot::isActive() const {
        return bot_active;
    }

    bool CleanerBot::isValid() const {
        return (bot_location != nullptr && strlen(bot_location) != 0 &&
                bot_battery >= 0.0 && bot_brush > 0);
    }

    void CleanerBot::display() const {
        cout.setf(ios::left);
        cout << "| " << setw(10) << bot_location;
        cout.unsetf(ios::left);
        cout << " | " << fixed << setprecision(1) << setw(7) << bot_battery;
        cout << " | " << setw(18) << bot_brush << " | " << setw(6);
        cout.setf(ios::left);
        if (isActive()) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout.unsetf(ios::left);
        cout << " |" << endl;
    }

    void sort(CleanerBot *bot, short num_bots) {
        int i, j, maxPos;
        for (i = 0; i < num_bots; i++) {
            maxPos = i;
            for (j = i + 1; j < num_bots; j++) {
                if (bot[j].getBattery() > bot[maxPos].getBattery())
                    maxPos = j;
            }
            if (maxPos != i) {
                if (bot[i].isValid() && bot[maxPos].isValid()) {
                    CleanerBot temp;
                    temp.set(bot[i].getLocation(), bot[i].getBattery(), bot[i].getBrush(), bot[i].isActive());
                    bot[i].set(bot[maxPos].getLocation(), bot[maxPos].getBattery(), bot[maxPos].getBrush(), bot[maxPos].isActive());
                    bot[maxPos].set(temp.getLocation(), temp.getBattery(), temp.getBrush(), temp.isActive());
                }
            }
        }
    }

    void batteryLow(CleanerBot *bot, short num_bots) {
        int count = 0;
        for (int i = 0; i < num_bots; i++) {
            if (bot[i].getBattery() <= 30.0 && bot[i].isValid())
                count++;
        }

        if (count == 0)
            return;

        cout << "|====================================================|" << endl;
        cout << "| LOW BATTERY WARNING:                               |" << endl;
        cout << "|====================================================|" << endl;
        cout << "| Number of robots to be charged: " << count << "                  |" << endl;
        cout << "| Sorting robots based on their available power:     |" << endl;
        cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
        cout << "|------------+---------+--------------------+--------|" << endl;
        sort(bot, num_bots);
        for (int i = 0; i < num_bots; i++) {
            if (bot[i].isValid()) {
                bot[i].display();
            }
        }
        cout << "|====================================================|" << endl;
    }

    int report(CleanerBot *bot, short num_bots) {
        cout << "         ------ Cleaner Bots Report -----" << endl;
        cout << "     ---------------------------------------" << endl;
        cout << "| Location   | Battery |  Number of Brushes | Active |" << endl;
        cout << "|------------+---------+--------------------+--------|" << endl;
        for (int i = 0; i < num_bots; i++) {
            if (bot[i].isValid()) {
                bot[i].display();
            }
        }
        cout << endl;

        batteryLow(bot, num_bots);

        return 0;
    }
}