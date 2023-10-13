#include "myfuncs.h"
#include <iostream>
#include <string>
#include <limits>
#include <sstream>

double* func(double* a, int n) {
    double* b = new double[n];
    b[0] = a[0];
    b[n - 1] = a[n - 1];
    for (int i = 1; i < n - 1; i++) {
        b[i] = ((a[i + 1] - a[i]) / 3);
    }
    return b;
}

int oneOrZero() {
    int a;
    std::string m;
    getline(std::cin, m);
    while (m.length() != 1 || (m[0] != '0' && m[0] != '1')) {
        std::cout << "!!ops!!\nInput 1 or 0" << std::endl;
        std::cin.clear();
        getline(std::cin, m);
    }
    a = m[0] - '0';
    return a;
}

int getNatural(const std::string& prompt) {
    int n;
    std::string m;
    while (true) {
        std::cout << prompt;
        getline(std::cin, m);
        std::stringstream ss(m);
        if (ss >> n && ss.eof() && n > 0) {
            break;
        } else {
            std::cout << "Error, try again with a positive integer:\n";
        }
    }
    return n;
}

double getRealNumber(const std::string& prompt) {
    double n;
    std::string m;
    while (true) {
        std::cout << prompt;
        getline(std::cin, m);
        std::stringstream ss(m);
        if (ss >> n && ss.eof()) {
            break;
        } else {
            std::cout << "Error, try again with a valid real number:\n";
        }
    }
    return n;
}
