#include <iostream>
using namespace std;

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int trans[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            trans[j][i] = arr[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }

    int row = 1, sum = 0;
    while (row <= 3)
    {
        for (int i = 0; i < 3; i++)
        {
            if (row == i)
            {
                sum += arr[row][i];
            }
        }
        row++;
    }
    cout << "Sum: " << sum;

    return 0;
}