#include <iostream>
using namespace std;

void printMatrix(int** matrix, int rows, int cols);
void searching(int** matrix, int n, int m, int key);

int main() {
    int rows, cols, key;
    
    // Taking dimensions input from the user
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    cout << "Enter key: ";
    cin >> key;
    
    // Dynamically allocating a 2D array
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    
    // Taking elements input from the user
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    // Calling the search function
    searching(matrix, rows, cols, key);
    
    // Calling the printMatrix function
    printMatrix(matrix, rows, cols);
    
    // Deallocating the memory
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}

void searching(int** matrix, int n, int m, int key) {
    bool found = false; // Initialize the flag to false
    int row = -1, col = -1; // Initialize row and col to invalid indices

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == key) {
                found = true;
                row = i;
                col = j;
                break; // Exit the inner loop if the key is found
            }
        }
        if (found) {
            break; // Exit the outer loop if the key is found
        }
    }

    if (found) {
        cout << "Key Found at coordinates: " << row << " " << col << endl;
    } else {
        cout << "Key doesn't exist" << endl;
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
