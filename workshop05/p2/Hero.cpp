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

#include "Hero.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds {
    Hero::Hero() {
        this->setEmpty();
    }

    Hero::Hero(const char *name, Power *power, int numPower) {
        if (name == nullptr || name[0] == '\0') {
            this->setEmpty();
            return;
        }

        strcpy(m_name, name);
        m_num_power = numPower;
        m_power = new Power[m_num_power];
        for (int i = 0; i < m_num_power; i++) {
            m_power[i].createPower(power[i].checkName(), power[i].checkRarity());
        }
        this->updatePowerLevel();
    }

    Hero::~Hero() {
        if (m_power != nullptr)
            delete[] m_power;
    }

    void Hero::setEmpty() {
        if (m_power != nullptr)
            delete[] m_power;

        m_name[0] = '\0';
        m_power = nullptr;
        m_num_power = 0;
        m_power_level = 0;
    }

    int Hero::getPowerLevel() const {
        return m_power_level;
    }

    void Hero::updatePowerLevel() {
        if (m_power == nullptr) {
            m_power_level = 0;
            return;
        }

        int count = 0;
        for (int i = 0; i < m_num_power; i++) {
            count += m_power[i].checkRarity();
        }
        m_power_level = count * m_num_power;
    }

    Hero &Hero::operator+=(Power &power) {
        if (m_power == nullptr) {
            m_power = new Power;
            m_power->createPower(power.checkName(), power.checkRarity());
            m_num_power++;
            return *this;
        }

        m_num_power++;

        Power temp[m_num_power];
        for (int i = 0; i < m_num_power; i++) {
            temp[i].createPower(m_power[i].checkName(), m_power[i].checkRarity());
        }

        delete[] m_power;

        m_power = new Power[m_num_power];

        for (int i = 0; i < m_num_power - 1; i++) {
            m_power[i].createPower(temp[i].checkName(), temp[i].checkRarity());
        }

        m_power[m_num_power - 1].createPower(power.checkName(), power.checkRarity());

        this->updatePowerLevel();

        return *this;
    }

    Hero &Hero::operator-=(int power) {
        m_power_level -= power;
        return *this;
    }

    std::ostream &Hero::display(std::ostream &os) const {
        os << "Name: " << m_name << endl;
        displayDetails(m_power, m_num_power);
        os << "Power Level: " << m_power_level;
        return os;
    }

    bool operator<(Hero &lhs, Hero &rhs) {
        return (lhs.getPowerLevel() < rhs.getPowerLevel());
    }

    bool operator>(Hero &lhs, Hero &rhs) {
        return (lhs.getPowerLevel() > rhs.getPowerLevel());
    }

    void operator<<(Hero &hero, Power &power) {
        hero += power;
    }

    void operator>>(Power &power, Hero &hero) {
        hero += power;
    }

    std::ostream &operator<<(std::ostream &os, const Hero &hero) {
        hero.display(os);
        return os;
    }
}