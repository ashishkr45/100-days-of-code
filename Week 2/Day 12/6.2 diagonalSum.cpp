/*
Primary Diagonal: are the elements whose index of i and j are equal.(i = j)

Secondary Diagonal: In this the index of i are increasing and for j it's decreasing there is a formula i.e. (j = n - i - 1)

in odd matrix there will be common elements like in 3x3 matrix
    eg: 1 2 3
        4 5 6
        7 8 9

    5 will be common in both the diagonal so for the sum we'll reduce the common elements the return the final output.

for the common elements both the conditions will be trur i.e. i = j and
j = n - i - 1.
    elements which are initiall counted in primary dia shall not be counted further in seconday dia.
*/

#include <iostream>
using namespace std;

int diagonalSum(int matrix[][4], int n);
void printArr(int matrix[][4], int n);

int main()
{
    // int n;
    // cout << "Enter rows of the square matrix: ";
    // cin >> n;

    // cout << "Enter the elements: " << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cin >> matrix[i][j];
    //     }
    // }
    int matrix[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "Sum of diagonal Elemets: " << diagonalSum(matrix, 4) << endl;

    return 0;
}

int diagonalSum(int matrix[][4], int n)
{
    int sum = 0;

    /*Time complexity O(N^2)*/
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                sum += matrix[i][j];
            }
            else if (j == n - i - 1)
            {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}