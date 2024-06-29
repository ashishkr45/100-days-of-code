#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter rows: ";
    cin >> n;
    cout << "Enter columns: ";
    cin >> m;

    cout << "Enter the elements: " << endl;

    int matrix[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int sRow = 0, sCol = 0, eRow = n - 1, eCol = m - 1;

    while (sRow <= eRow && sCol <= eCol)
    {
        // top
        for (int j = sCol; j <= eCol; j++)
        {
            cout << matrix[sRow][j] << " ";
        }
        sRow++; // Move to the next row

        // right
        for (int i = sRow; i <= eRow; i++) // Corrected loop condition
        {
            cout << matrix[i][eCol] << " "; // Added space for readability
        }
        eCol--; // Move to the previous column

        if (sRow <= eRow) // Check if there are remaining rows
        {
            // bottom
            for (int j = eCol; j >= sCol; j--) // Corrected loop condition
            {
                cout << matrix[eRow][j] << " "; // Added space for readability
            }
            eRow--; // Move to the previous row
        }

        if (sCol <= eCol) // Check if there are remaining columns
        {
            // left
            for (int i = eRow; i >= sRow; i--) // Corrected loop condition
            {
                cout << matrix[i][sCol] << " "; // Added space for readability
            }
            sCol++; // Move to the next column
        }
    }

    return 0;
}
