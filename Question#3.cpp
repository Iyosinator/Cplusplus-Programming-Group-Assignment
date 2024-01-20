#include <iostream>

using namespace std;
// Function to calculate power without using pow function
double calculatePower(int base, int exponent) {
    double result = 1.0;
    if (exponent == 0 && base == 0){
        cout << "Undefined or 1" << endl;
    }
    if (exponent >= 0) {
        for (int i = 0; i < exponent; ++i) {
            result *= base;
        }
    } else {
        for (int i = 0; i < -exponent; ++i) {
            result /= base;
        }
    }

    return result;
}

int main() {
    char choice;
    
    do {
        int base, exponent;

        // Get user input
        cout << "Enter the base: ";
        cin >> base;

        cout << "Enter the exponent: ";
        cin >> exponent;

        // Calculate and display result
        double result = calculatePower(base, exponent);
        cout << base << "^" << exponent << " = " << result << endl;

        // Ask user if they want to run the program again
        cout << "Do you want to calculate another power? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
