#include <iostream>
using namespace std;
int main() {
    int start, end;
    
    cout << "Welcome to the program of Floyd Number" << endl;
    cout << "Please Enter the starting number: ";
    cin >> start;

    cout << "Please Enter the ending number: ";
    cin >> end;

    int num = start;  // Initialize the number to be printed

    for (int i = 1; num <= end; i++) {  // Loop for rows
        for (int j = 1; j <= i; j++) {  // Loop for columns
            cout << num << " ";  // Print the number
            num++;  // Increment the number
        }
        cout << endl;  // Move to the next line after each row
    }
    return 0;
}
