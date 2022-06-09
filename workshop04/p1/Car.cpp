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

#include "Car.h"
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

namespace sdds {
    void Car::resetInfo() {
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        m_year = 0;
        m_code = 0;
        m_price = 0.0;
    }

    Car::Car() {
        resetInfo();
    }

    Car::Car(const char *type, const char *brand, const char *model,
             int year, int code, double price) {

        if (type == nullptr || brand == nullptr || model == nullptr) {
            resetInfo();
            return;
        }

        m_type = new char[strlen(type) + 1];
        strcpy(m_type, type);

        m_brand = new char[strlen(brand) + 1];
        strcpy(m_brand, brand);

        m_model = new char[strlen(model) + 1];
        strcpy(m_model, model);

        m_year = year;
        m_code = code;
        m_price = price;
    }

    Car::~Car() {
        if (m_type != nullptr) {
            delete[] m_type;
            m_type = nullptr;
        }

        if (m_brand != nullptr) {
            delete[] m_brand;
            m_brand = nullptr;
        }

        if (m_model != nullptr) {
            delete[] m_model;
            m_model = nullptr;
        }
    }

    Car &Car::setInfo(const char *type, const char *brand, const char *model,
                      int year, int code, double price) {
        if (m_type != nullptr) {
            delete[] m_type;
            m_type = nullptr;
        }

        if (m_brand != nullptr) {
            delete[] m_brand;
            m_brand = nullptr;
        }

        if (m_model != nullptr) {
            delete[] m_model;
            m_model = nullptr;
        }

        if (type != nullptr) {
            m_type = new char[strlen(type) + 1];
            strcpy(m_type, type);
        } else {
            m_type = nullptr;
        }

        if (brand != nullptr) {
            m_brand = new char[strlen(brand) + 1];
            strcpy(m_brand, brand);
        } else {
            m_brand = nullptr;
        }

        if (model != nullptr) {
            m_model = new char[strlen(model) + 1];
            strcpy(m_model, model);
        } else {
            m_model = nullptr;
        }

        m_year = year;
        m_code = code;
        m_price = price;

        return *this;
    }

    void Car::printInfo() const {
        cout.setf(ios::left);
        cout << "| " << setw(10) << m_type;
        cout << " | " << setw(16) << m_brand;
        cout << " | " << setw(16) << m_model;
        cout.unsetf(ios::left);
        cout << " | " << m_year << " |  " << m_code << " | ";
        cout << fixed << setprecision(2) << setw(9) << m_price << " |" << endl;
    }

    bool Car::isValid() const {
        return (m_type != nullptr && strcmp(m_type, "") != 0 &&
                m_brand != nullptr && strcmp(m_brand, "") != 0 &&
                m_model != nullptr && strcmp(m_model, "") != 0 &&
                m_year >= 1990 && m_code >= 100 && m_code <= 999 && m_price > 0.0);
    }

    bool Car::isSimilarTo(const Car &car) const {
        if (!isValid() || !car.isValid())
            return false;
        return (strcmp(m_type, car.m_type) == 0 &&
                strcmp(m_brand, car.m_brand) == 0 &&
                strcmp(m_model, car.m_model) == 0 && m_year == car.m_year);
    }

    bool has_similar(const Car car[], const int num_cars) {
        for (int i = 0; i < num_cars; i++) {
            for (int j = i + 1; j < num_cars; j++) {
                if (car[i].isSimilarTo(car[j])) {
                    return true;
                }
            }
        }
        return false;
    }

    bool has_invalid(const Car car[], const int num_cars) {
        for (int i = 0; i < num_cars; i++) {
            if (!car[i].isValid())
                return true;
        }
        return false;
    }

    void print(const Car car[], const int num_cars) {
        for (int i = 0; i < num_cars; i++) {
            if (car[i].isValid())
                car[i].printInfo();
        }
    }
};