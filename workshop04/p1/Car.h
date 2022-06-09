/*
*****************************************************************************
Full Name : Yongda Long
Student ID# : 172800211
Email : ylong9@myseneca.ca
Section : OOP244NGG
Date : June 09, 2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

namespace sdds {
    class Car {
        char *m_type;
        char *m_brand;
        char *m_model;
        int m_year;
        int m_code;
        double m_price;
        void resetInfo();

    public:
        Car();
        Car(const char *type, const char *brand, const char *model,
            int year = 2022, int code = 100, double price = 1.0);
        ~Car();
        Car &setInfo(const char *type, const char *brand, const char *model,
                     int year, int code, double price);
        void printInfo() const;
        bool isValid() const;
        bool isSimilarTo(const Car &car) const;
    };
    bool has_similar(const Car car[], const int num_cars);
    bool has_invalid(const Car car[], const int num_cars);
    void print(const Car car[], const int num_cars);
};