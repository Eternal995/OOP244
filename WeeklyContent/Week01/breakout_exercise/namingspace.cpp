#include <iostream>
#include "namingspace.h"

using namespace std;

namespace Long {
    int show(const char x) {
        int i = 0;
        int count = 0;
        for (i = 0; i < 12; i++) {
            cout << x;
            count++;
        }
        cout << endl;
        return count;
    }
}

