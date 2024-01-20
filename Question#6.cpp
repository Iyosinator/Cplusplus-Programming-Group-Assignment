#include <iostream>
#include <map>
#include <string>

using namespace std;

// Global variables to store user accounts
map<string, string> userAccounts;
map<string, double> userBalances;

// Function declarations
void displayMenu();
bool createAccount();
bool login();
void performTransactions(const string& userId);
void depositMoney(const string& userId);
void withdrawMoney(const string& userId);
void requestBalance(const string& userId);

int main() {
    char choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 'c':
                if (createAccount()) {
                    cout << "Thank You! Your account has been created!" << endl;
                }
                break;

            case 'l':
                if (login()) {
                    performTransactions(userAccounts["current_user"]);
                } else {
                    cout << "******** LOGIN FAILED! ********" << endl;
                }
                break;

            case 'q':
                cout << "Thanks for stopping!" << endl;
                break;

            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 'q');

    return 0;
}

void displayMenu() {
    cout << "Hi! Welcome to AASTU ATM Machine!" << endl;
    cout << "Please select an option from the menu below:" << endl;
    cout << "l -> Login" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
}

bool createAccount() {
    string userId, password;

    cout << "Please enter your user name: ";
    cin >> userId;

    cout << "Please enter your password: ";
    cin >> password;

    // Check if user already exists
    if (userAccounts.find(userId) != userAccounts.end()) {
        cout << "User already exists. Please choose a different user id." << endl;
        return false;
    }

    // Create new account
    userAccounts[userId] = password;
    userBalances[userId] = 0.0;

    return true;
}

bool login() {
    string userId, password;

    cout << "Please enter your user id: ";
    cin >> userId;

    cout << "Please enter your password: ";
    cin >> password;

    // Check if user exists and password is correct
    if (userAccounts.find(userId) != userAccounts.end() && userAccounts[userId] == password) {
        userAccounts["current_user"] = userId;
        return true;
    }

    return false;
}

void performTransactions(const string& userId) {
    char choice;

    do {
        cout << "d -> Deposit Money" << endl;
        cout << "w -> Withdraw Money" << endl;
        cout << "r -> Request Balance" << endl;
        cout << "q -> Quit" << endl;
        cout << "> ";

        cin >> choice;

        switch (choice) {
            case 'd':
                depositMoney(userId);
                break;

            case 'w':
                withdrawMoney(userId);
                break;

            case 'r':
                requestBalance(userId);
                break;

            case 'q':
                cout << "Thanks you !!! See you soon" << endl;
                break;

            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 'q');
}

void depositMoney(const string& userId) {
    double amount;

    cout << "Amount of deposit: (br) ";
    cin >> amount;

    userBalances[userId] += amount;
}

void withdrawMoney(const string& userId) {
    double amount;

    cout << "Amount of withdrawal: (br)";
    cin >> amount;

    // Check if sufficient balance
    if (userBalances[userId] >= amount) {
        userBalances[userId] -= amount;
    } else {
        cout << "Insufficient balance. Withdrawal failed." << endl;
    }
}

void requestBalance(const string& userId) {
    cout << "Your balance is (br) " << userBalances[userId] << "." << endl;
}
