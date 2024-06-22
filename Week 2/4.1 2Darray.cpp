#include <iostream>
using namespace std;

int main()
{
    int m, n;

    cout << "Enter number of Rows: ";
    cin >> n;

    cout << "Enter number of Columns: ";
    cin >> m;

    int arr[n][m];

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "The array elements are:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
