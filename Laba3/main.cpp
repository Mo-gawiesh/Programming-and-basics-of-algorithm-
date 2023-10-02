#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "myfuncs.h"
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int j = 1, k, l, o;
    while (j == 1) {
        cout << "Where to get the input data from? (file-1, console-0)" << endl;
        k = one_or_zero();
        cout << "Where to output the result? (file-1, console-0)" << endl;
        l = one_or_zero();
        int** a = new int* [6];
        for (int i = 0; i < 6; i++)
            a[i] = new int[6];
        int** c = new int* [6];
        for (int i = 0; i < 6; i++)
            c[i] = new int[6];
        int b[6];
        if (k == 0) {
            cout << "Do use randomizer for the first matrix (1-yes, 0-no)?" << endl;
            o = one_or_zero();
            if (o == 0) {
                for (int i = 0; i < 6; i++) {
                    for (int j = 0; j < 6; j++) {
                        cout << "Input [" << i + 1 << "][" << j + 1 << "]: ";
                        a[i][j] = natural(i);
                    }
                }
            }
            else {
                for (int i = 0; i < 6; i++) {
                    for (int j = 0; j < 6; j++) {
                        a[i][j] = rand() % 100;
                    }
                }
            }
            cout << "Do use randomizer for the second matrix (1-yes, 0-no)?" << endl;
            o = one_or_zero();
            if (o == 0) {
                for (int i = 0; i < 6; i++) {
                    for (int j = 0; j < 6; j++) {
                        cout << "Input [" << i + 1 << "][" << j + 1 << "]: ";
                        c[i][j] = natural(i);
                    }
                }
            }
            else {
                for (int i = 0; i < 6; i++) {
                    for (int j = 0; j < 6; j++) {
                        c[i][j] = rand() % 100;
                    }
                }
            }
        }
        else if (k == 1) {
            ifstream file;
            file.open("input.txt");
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    file >> a[i][j];
                }
            }
            j = 0;
        }
        func(a, b, c);
        if (l == 1) {
            ofstream file;
            file.open("output.txt");
            file << "Input data:\n";
            file << "The matrix-1\n";
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    file << setw(4) << a[i][j] << " ";
                }
                file << endl;
            }
            file << "The matrix-2\n";
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    file << setw(4) << c[i][j] << " ";
                }
                file << endl;
            }
            file << "Result: \n";
            for (int i = 0; i < 6; i++)
                file << b[i] << " ";
        }
        else if (l == 0) {
            cout << "Input data:\n";
            cout << "The matrix-1\n";
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    cout << setw(4) << a[i][j] << " ";
                }
                cout << endl;
            }
            cout << "The matrix-2\n";
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    cout << setw(4) << c[i][j] << " ";
                }
                cout << endl;
            }
            cout << "Result: \n";
            for (int i = 0; i < 6; i++)
                cout << b[i] << " ";
        }
        if (j == 1) {
            cout << endl << "Continue (0-no, 1-yes)";
            j = one_or_zero();
        }
    }
    return 0;
}
