#include <iostream>
#include <fstream>
#include "myfuncs.h"
#include "constants.h"

int main() {
    int n{0};
    int k{0};
    int l{0};
    bool repeat{true};

    while (repeat) {
        std::cout << "Where to get the input data from? (file-1, console-0):\n";
        k = oneOrZero();

        std::cout << "Where to output the result? (file-1, console-0):\n";
        l = oneOrZero();

        if (k == 0) {
            n = getNatural("Input n: "); // Get a valid positive integer
            double* a = new double[n];

            for (int i = 0; i < n; i++) {
                a[i] = getRealNumber("Input a" + std::to_string(i + 1) + ": "); // Get a valid real number
            }

            double* b = func(a, n);

            if (l == 1) {
                std::ofstream file(OUTPUT_FILE_PATH);
                file << "Input data:\n";
                file << "n=" << n << std::endl;
                for (int i = 0; i < n; i++) file << "a" << i + 1 << "=" << a[i] << std::endl;
                file << "Result:\n";
                for (int i = 0; i < n; i++) file << "b" << i + 1 << "=" << b[i] << std::endl;
                file.close();
            } else if (l == 0) {
                std::cout << "Input data:\n";
                std::cout << "n=" << n << std::endl;
                for (int i = 0; i < n; i++) std::cout << "a" << i + 1 << "=" << a[i] << std::endl;
                std::cout << "Result:\n";
                for (int i = 0; i < n; i++) std::cout << "b" << i + 1 << "=" << b[i] << std::endl;
            }

            delete[] a;
            delete[] b;
        } else if (k == 1) {
            std::ifstream file(INPUT_FILE_PATH);
            file >> n;
            double* a = new double[n];

            for (int i = 0; i < n; i++) {
                file >> a[i];
            }

            double* b = func(a, n);

            if (l == 1) {
                std::ofstream outFile(OUTPUT_FILE_PATH);
                outFile << "Input data:\n";
                outFile << "n=" << n << std::endl;
                for (int i = 0; i < n; i++) outFile << "a" << i + 1 << "=" << a[i] << std::endl;
                outFile << "Result:\n";
                for (int i = 0; i < n; i++) outFile << "b" << i + 1 << "=" << b[i] << std::endl;
                outFile.close();
            } else if (l == 0) {
                std::cout << "Input data:\n";
                std::cout << "n=" << n << std::endl;
                for (int i = 0; i < n; i++) std::cout << "a" << i + 1 << "=" << a[i] << std::endl;
                std::cout << "Result:\n";
                for (int i = 0; i < n; i++) std::cout << "b" << i + 1 << "=" << b[i] << std::endl;
            }

            delete[] a;
            delete[] b;
        }

        std::cout << "Continue (0-no; 1-yes)? ";
        repeat = oneOrZero();
    }

    return 0;
}
