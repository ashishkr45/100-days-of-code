/*
-it's only possibe for those matrix which are row and column wise sorted.

For good explaination watch the video in folder 18, video 8 at time 10:00, it's explained really well there.
    starting(starting cell) point will always be matrix[0][m-1] or matrix[n-1][0]

    sudo code:
    cell start: matrix[0][m-1]  row = 0 and column = m - 1

    loop(row<n && col >= 0){
        cell == key - key found
        cell < key - that means we need to go down, that means row no inc.
        cell > key - that means we need ti go left, that means column--
    }

    for example:
    the matrix be:
        10 20 30 40
        15 25 35 45
        27 29 37 48
        32 33 39 50

    and the key be 33

Time complixity of this method will be O(n+m)
*/

#include <iostream>
using namespace std;

void stairs(int **matrix, int n, int m, int key);

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
    stairs(matrix, rows, cols, key);

    // Deallocating the memory
    for (int i = 0; i < rows; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

void stairs(int **matrix, int n, int m, int key)
{
    int r = 0, c = m - 1;

    while (r < n && c >= 0)
    {
        if (matrix[r][c] > key)
        {
            c--;
        }
        else if (matrix[r][c] < key)
        {
            r++;
        }
        else // if matrix[r][c] == key.
        {
            cout << "Key Found! row = " << r << " and column = " << c << endl;
            return;
        }
    }
    // If we exit the loop, the key was not found
    cout << "Key not found" << endl;
}