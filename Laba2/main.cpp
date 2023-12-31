#include <iostream>
#include <string>
#include <fstream>
#include "myfuncs.h"
#include "constants.h"
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    int i{}, j{1}, k, l;
    double s{};

    while (j == 1) {
        cout << "Where to get the input data from? (file-1, console-0)" << endl;
        k = one_or_zero();
        cout << "Where to output the result? (file-1, console-0)" << endl;
        l = one_or_zero();

        if (k == 0) {
            cout << "Input n: ";
            n = natural();
        } else if (k == 1) {
            j = 0;
            ifstream inputFile; // Rename the file variable
            inputFile.open(INPUT_FILE_PATH);
            inputFile >> n;
        }

        for (int i = 1; i <= n; i++) s = s + pow((-1), int(log10(i))) / i;

        if (l == 1) {
            ofstream outputFile; // Rename the file variable
            outputFile.open(OUTPUT_FILE_PATH);
            outputFile << "Input data:\n";
            outputFile << "n=" << n << endl;
            outputFile << "Result:\n" << s;
        } else if (l == 0) {
            cout << "Input data:\n";
            cout << "n=" << n << endl;
            cout << "Result:\n" << s;
        }
        s = 0;

        if (j == 1) {
            cout << endl << "Continue (0-no; 1-yes)?";
            j = natural();
        }
    }
    return 0;
}
