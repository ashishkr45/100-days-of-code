/*
Row-wise Binary search:
    In this first we'll search in row 1 then 2 and so on in all the rows
    time complexity of Binary search is log m (m is num os elements in that row or no of columns) therefore for this the time complexity will be O(n x log m) where n is number of rows.

Column-wise Binary Search:
    everything will be same but the time complexity will be (m x log n)
*/

#include <iostream>
using namespace std;

void binarySearching(int **matrix, int n, int m, int key);

int main()
{

    int rows, cols, key;

    // Taking dimensions input from the user
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    cout << "Enter key: ";
    cin >> key;

    // Dynamically allocating a 2D array
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols];
    }

    // Taking elements input from the user
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    // Calling the search function
    binarySearching(matrix, rows, cols, key);

    // Deallocating the memory
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

void binarySearching(int **matrix, int n, int m, int key)
{
    bool flag = false;
    int row = -1, col = -1; // Initialize row and col to invalid indices

    for (int i = 0; i < n; i++)
    {
        int st = 0, end = m;
        while (st <= end)
        {
            int mid = (st + end) / 2;
            if (matrix[i][mid] == key)
            {
                flag = true;
                row = i;
                col = mid;
                break;
            }
            else if (matrix[i][mid] > key)
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        if (flag)
        {
            break; // Exit the outer loop if the key is found
        }
    }

    if (flag)
    {
        cout << "Key found! row = " << row << " and column = " << col << endl;
    }
    else
    {
        cout << "Key not found!";
    }
}