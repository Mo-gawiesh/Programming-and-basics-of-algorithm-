#include <iostream>
#include <string>
#include <limits>
using namespace std;

int one_or_zero(int a) {
    int m;
    while (!(cin >> m) || (a = m) != m || (m != 0 && m != 1)) {
        cout << "!!!Error!!!" << endl;
        cout << "Input 1 or 0" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return a;
}

int natural(int n) {
    int m;
    while (!(cin >> m) || m <= 0 || (n = m) != m) {
        cout << "Error, try again:" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return n;
}

char symbol(char c) {
    string s;
    while (!(cin >> s) || s.length() > 1) {
        cout << "!!!Input one symbol at a time!!!" << endl;
    }
    c = s[0];
    return c;
}
