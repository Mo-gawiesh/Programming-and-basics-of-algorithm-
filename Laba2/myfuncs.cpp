#include <iostream>
#include <limits>
#include <cmath>
#include "myfuncs.h"
#include <sstream>

int one_or_zero() {
    std::string m;
    getline(std::cin, m);
    while (m.length() != 1 || (stoi(m) != 0 && stoi(m) != 1)) {
        std::cout << "Input 1 or 0" << std::endl;
        getline(std::cin, m);
    }
    int a = stoi(m);
    return a;
}

int natural() {
    int n;
    while (!(std::cin >> n) || n <= 0 || std::cin.peek() != '\n') {
        std::cout << "Error, try again:\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
