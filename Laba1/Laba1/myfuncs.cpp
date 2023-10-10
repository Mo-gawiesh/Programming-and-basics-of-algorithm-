#include <iostream>
#include <string>
#include <limits>
#include <sstream>
using namespace std;

double* func(double* a, int n) {
    double* b = new double[n];
    b[0] = a[0];
    b[n - 1] = a[n - 1];
    for (int i = 1; i < n - 1; i++) {
        b[i] = ((a[i + 1] - a[i]) / 3);
    }
    return b;
}

int one_or_zero() {
    int a;
    string m;
    getline(cin, m);
    while (m.length() != 1 || (m[0] != '0' && m[0] != '1')) {
        cout << "!!ops!!\nInput 1 or 0" << endl;
        cin.clear();
        getline(cin, m);
    }
    a = m[0] - '0';
    return a;
}

int natural() {
    int n;
    string m;
    while (true) {
        getline(cin, m);
        stringstream ss(m);
        if (ss >> n && ss.eof() && n > 0) {
            break;
        } else {
            cout << "Error, try again with a positive integer:\n";
        }
    }
    return n;
}

double realnum() {
    double n;
    string m;
    while (true) {
        getline(cin, m);
        stringstream ss(m);
        if (ss >> n && ss.eof()) {
            break;
        } else {
            cout << "Error, try again with a valid real number:\n";
        }
    }
    return n;
}
