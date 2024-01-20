#include <iostream>

using namespace std;

int main() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int matrix[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element at matrix row " << i + 1 << " column " << j + 1 << ": ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nOriginal matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nTranspose of the matrix:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
