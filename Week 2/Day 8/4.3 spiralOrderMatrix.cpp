#include <iostream>
using namespace std;

int main()
{
    int row, column;
    cout << "Enter number of Rows: ";
    cin >> row;
    cout << "Enter number of Column: ";
    cin >> column;

    int arr[row][column];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> arr[i][j];
        }
    }

    /*Sprial Order Print*/
    int rowStart = 0, rowEnd = row - 1, colStart = 0, colEnd = column - 1;

    while (rowStart <= rowEnd && colStart <= colEnd)
    {
        /*for row start*/
        for (int col = colStart; col <= colEnd; col++)
            cout << arr[rowStart][col] << " ";
        rowStart++;

        /*for column end*/
        for (int row = rowStart; row <= rowEnd; row++)
            cout << arr[row][colEnd] << " ";
        colEnd--;

        /*for row end*/
        for (int col = colEnd; col >= colStart; col--)
            cout << arr[rowEnd][col] << " ";
        rowEnd--;

        /*for column start*/
        for (int row = rowEnd; row >= rowStart; row--)
            cout << arr[row][colStart] << " ";
        colStart++;
    }

    return 0;
}