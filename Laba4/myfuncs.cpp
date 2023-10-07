#include <iostream>
#include <string>
#include <limits>
using namespace std;

int one_or_zero(int a) {
    string input;
    while (true) {
        cin >> input;
        if (input != "0" && input != "1") {
            cout << "!!!Error!!!" << endl;
            cout << "Input 1 or 0" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            a = stoi(input); // Convert the valid input to an integer
            break;           // Exit the loop when valid input is received
        }
    }
    return a;
}







int natural(int n) {
    int m;
    while (true) {
        if (!(cin >> m) || m <= 0) {
            cout << "Error, enter a positive integer:" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            n = m; // Assign the valid input value to 'n'
            break;  // Exit the loop when valid input is received
        }
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
