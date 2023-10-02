#include <iostream>
#include <fstream>
#include "myfuncs.h"
using namespace std;

int main()
{
    int n;
    string path;
    int i = 0, j = 1, k = 0, l = 0; // Initialize variables

    while (j == 1) {
        cout << "Where to get the input data from? (file-1, console-0)" << endl;
        k = one_or_zero(k);

        cout << "Where to output the result? (file-1, console-0)" << endl;
        l = one_or_zero(l);

        if (k == 0) {
            cout << "Enter n: ";
            n = natural(n);
        }
        else if (k == 1) {
            path = "input.txt";
            cout << "Enter the name of the input file or the path to the file (with .txt extension):" << endl;
            cin.ignore(100, '\n');
            getline(cin, path);
            ifstream file(path);

            while (!file.is_open()) {
                cout << "Incorrect input or the path is specified incorrectly. Please try again." << endl;
                getline(cin, path);
                file.open(path);
            }
            file >> n;
        }

        char* s = new char[n];

        if (k == 0) {
            for (i = 0; i < n; i++) {
                cout << "Input s" << i + 1 << ": ";
                s[i] = symbol(s[i]);
            }
        }
        else if (k == 1) {
            i = 0;
            ifstream file(path);

            while (i < n && file >> s[i]) {
                i++;
            }

            file.close();
        }

        int c = 0;
        for (i = 0; i < n - 2; i++) {
            if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
                c++;
            }
        }

        if (l == 1) {
            path = "output.txt";
            cout << "Enter the name of the output file or the path to the file (with .txt extension):" << endl;
            cin.ignore(100, '\n');
            getline(cin, path);

            ofstream file(path);
            if (file.is_open()) {
                file << "Input data:\n";
                file << "n=" << n << endl;
                for (i = 0; i < n; i++) {
                    file << "s" << i + 1 << "=" << s[i] << endl;
                }
                file << "Result: \n" << c;
                file.close();
            }
        }
        else if (l == 0) {
            cout << "Input data:\n";
            cout << "n=" << n << endl;
            for (i = 0; i < n; i++) {
                cout << "s" << i + 1 << "=" << s[i] << endl;
            }
            cout << "Result: \n" << c << endl;
        }

        delete[] s;

        cout << endl << "Continue (0 - no; 1 - yes)? ";
        j = one_or_zero(j);
    }

    return 0;
}
