#include <iostream>

using namespace std;

void checkPrime(int num) {
    if (num <= 1) {
        cout << num << " is neither prime nor composite." << endl;
    } else if (num % 2 == 0 && num != 2) {
        cout << num << " is not prime. It is composite, divisible by 2." << endl;
    } else {
        bool isPrime = true;
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) {
                cout << num << " is not prime. It is composite, divisible by " << i << "." << endl;
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            cout << num << " is a prime number." << endl;
        }
    }
}

int main() {
    char choice;

    do {
        int num;
        cout << "Enter an integer: ";
        cin >> num;

        if (num < 0 || static_cast<double>(num) != static_cast<int>(num)) {
            cout << num << " is neither composite nor prime (not a positive integer)." << endl;
        } else {
            checkPrime(num);
        }

        cout << "Do you want to check another number? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
