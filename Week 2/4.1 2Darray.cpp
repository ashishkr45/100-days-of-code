#include <iostream>
using namespace std;

int main()
{

    int m, n;
    int arr[n][m];

    cout << "Enter number of Row: ";
    cin >> n;

    cout << "Enter number of coulmn: ";
    cin >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }

    return 0;
}