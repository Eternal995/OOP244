/*
*****************************************************************************
Full Name : Yongda Long
Student ID# : 172800211
Email : ylong9@myseneca.ca
Section : OOP244NGG
Date : , 2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

namespace sdds {
    class CleanerBot {
        char *bot_location;
        double bot_battery;
        int bot_brush;
        bool bot_active;

    public:
        CleanerBot();
        CleanerBot(const char *location, double battery, int brush, bool active);
        ~CleanerBot();
        void setEmpty();
        void set(const char *location, double battery, int brush, bool active);
        void setLocation(const char *location);
        void setActive(bool active);
        char *getLocation() const;
        double getBattery() const;
        int getBrush() const;
        bool isActive() const;
        bool isValid() const;
        void display() const;
    };
    void sort(CleanerBot *bot, short num_bots);
    void batteryLow(CleanerBot &bot, short num_bots);
    int report(CleanerBot *bot, short num_bots);
}