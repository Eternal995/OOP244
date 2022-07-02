/*
*****************************************************************************
Full Name : Yongda Long
Student ID# : 172800211
Email : ylong9@myseneca.ca
Section : OOP244NGG
Date : July 1, 2022

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#include "Numbers.h"
#include "Numbers.h" // intentional
#include <cstring>
#include <fstream>

using namespace std;

namespace sdds {
    Numbers::Numbers() {
        setEmpty();
        m_isOriginal = false;
    }

    Numbers::Numbers(const char *filename) {
        setEmpty();
        m_isOriginal = true;
        setFilename(filename);
        m_numCount = numberCount();
        if (m_numCount == 0 || !load()) {
            delete[] m_numbers;
            delete[] m_filename;
            setEmpty();
            m_isOriginal = false;
        } else {
            sort();
        }
    }

    Numbers::Numbers(const Numbers &source) {
        m_isOriginal = false;
        m_numCount = source.m_numCount;

        if (source.m_filename != nullptr) {
            m_filename = new char[strlen(source.m_filename) + 1];
            strcpy(m_filename, source.m_filename);
        } else {
            setEmpty();
            return;
        }

        m_numbers = new double[m_numCount];
        for (int i = 0; i < m_numCount; i++) {
            m_numbers[i] = source.m_numbers[i];
        }
    }

    Numbers &Numbers::operator=(const Numbers &source) {
        if (this == &source) {
            return *this;
        }
        // m_isOriginal = false;
        m_numCount = source.m_numCount;

        if (source.m_filename != nullptr) {
            setFilename(source.m_filename);
        } else {
            setEmpty();
            return *this;
        }

        if (m_numbers != nullptr) {
            delete[] m_numbers;
        }

        m_numbers = new double[m_numCount];
        for (int i = 0; i < m_numCount; i++) {
            m_numbers[i] = source.m_numbers[i];
        }
        return *this;
    }

    Numbers::~Numbers() {
        save();
        delete[] m_numbers;
        delete[] m_filename;
    }

    bool Numbers::isEmpty() const {
        return m_numbers == nullptr;
    }

    void Numbers::setEmpty() {
        m_numbers = nullptr;
        m_filename = nullptr;
        m_numCount = 0;
    }

    void Numbers::setFilename(const char *filename) {
        delete[] m_filename;
        m_filename = new char[strlen(filename) + 1];
        strcpy(m_filename, filename);
    }

    void Numbers::sort() {
        int i, j;
        double temp;
        for (i = m_numCount - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (m_numbers[j] > m_numbers[j + 1]) {
                    temp = m_numbers[j];
                    m_numbers[j] = m_numbers[j + 1];
                    m_numbers[j + 1] = temp;
                }
            }
        }
    }

    double Numbers::average() const {
        double aver = 0.0;
        if (!isEmpty()) {
            for (int i = 0; i < m_numCount; i++)
                aver += m_numbers[i];
            aver = aver / m_numCount;
        }
        return aver;
    }

    double Numbers::min() const {
        double minVal = 0.0;
        if (!isEmpty()) {
            minVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (minVal > m_numbers[i])
                    minVal = m_numbers[i];
        }
        return minVal;
    }

    double Numbers::max() const {
        double maxVal = 0.0;
        if (!isEmpty()) {
            maxVal = m_numbers[0];
            for (int i = 1; i < m_numCount; i++)
                if (maxVal < m_numbers[i])
                    maxVal = m_numbers[i];
        }
        return maxVal;
    }

    int Numbers::numberCount() const {
        ifstream ifs(m_filename);

        if (!ifs.is_open()) {
            return 0;
        }

        int numberLines = 0;
        double read;
        while (ifs >> read) {
            numberLines++;
        }

        ifs.close();

        return numberLines;
    }

    bool Numbers::load() {
        int numberLines = numberCount();

        if (numberLines == 0) {
            m_numCount = 0;
            return true;
        }

        if (m_numbers != nullptr) {
            delete[] m_numbers;
        }

        ifstream ifs(m_filename);

        m_numbers = new double[m_numCount];
        int i = 0;

        while (ifs >> m_numbers[i]) {
            i++;
        }

        ifs.close();

        return (i == numberLines);
    }

    void Numbers::save() const {
        if (isEmpty() || !m_isOriginal) {
            return;
        }

        ofstream ofs(m_filename);

        for (int i = 0; i < m_numCount; i++) {
            ofs << m_numbers[i] << endl;
        }

        ofs.close();
    }

    Numbers &Numbers::operator+=(double number) {
        double *temp = nullptr;
        temp = new double[m_numCount + 1];
        for (int i = 0; i < m_numCount; i++) {
            temp[i] = m_numbers[i];
        }
        m_numCount++;
        delete[] m_numbers;
        temp[m_numCount - 1] = number;
        m_numbers = temp;
        temp = nullptr;
        sort();
        return *this;
    }

    ostream &Numbers::display(ostream &os) const {
        if (isEmpty()) {
            os << "Empty list";
            return os;
        }

        os << "=========================" << endl;
        if (m_isOriginal) {
            os << m_filename << endl;
        } else {
            os << "*** COPY ***" << endl;
        }
        for (int i = 0; i < m_numCount - 1; i++) {
            os << m_numbers[i] << ", ";
        }
        os << m_numbers[m_numCount - 1] << endl;
        os << "-------------------------" << endl;
        os << "Total of " << m_numCount << " number(s)" << endl;
        os << "Largest number:  " << max() << endl;
        os << "Smallest number: " << min() << endl;
        os << "Average :        " << average() << endl;
        os << "=========================";
        return os;
    }

    ostream &operator<<(ostream &os, const Numbers &N) {
        N.display(os);
        return os;
    }

    istream &operator>>(istream &is, Numbers &N) {
        double number;
        is >> number;
        N += number;
        return is;
    }
}
