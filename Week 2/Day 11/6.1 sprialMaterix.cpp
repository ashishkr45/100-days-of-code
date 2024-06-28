#include <iostream>
using namespace std;

void sprialMatrix(int matrix[][4], int n, int m);
// we always have to pass some value for the size.

int main()
{
    int n, m;
    cout << "Enter rows: ";
    cin >> n;
    cout << "Enter column: ";
    cin >> m;

    cout << "Enter the elements: " << endl;

    int matrix[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j];
        }
    }

    sprialMatrix(matrix, n, m);

    return 0;
}

void sprialMatrix(int *matrix, int n, int m)
{
    int sRow = 0, sCol = 0, eRow = n - 1, eCol = m - 1;

    // top
    for (int j = sCol; j <= eCol; j++)
    {
        cout << matrix[sRow][j];
    }

    // right
    for (int i = sRow + 1; i <= eRow; i++)
    {
        cout << matrix[i][eCol];
    }

    // bottom
    for (int j = eCol - 1; j >= sCol; j)
        --
        {
            cout << matrix[eRow][j];
        }

    // left
    for (int i = eRow - 1; i >= sRow + 1; i--)
    {
        cout << matrix[i][sCol];
    }

    sRow++;
    sCol++;
    eRow--;
    eCol--;

    return;
}