#include <iostream>
#include <limits>
using namespace std;

int one_or_zero() {
    string m;
    getline(cin, m);
    while (m.length() != 1 || (stoi(m) != 0 && stoi(m) != 1)) {
        cout << "\nInput 1 or 0" << endl;
        getline(cin, m);
    }
    int a = stoi(m);
    return a;
}

int natural() {
    int n;
    while (!(cin >> n) || n <= 0 || cin.peek() != '\n') {
        cout << "Error, try again:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return n;
}
