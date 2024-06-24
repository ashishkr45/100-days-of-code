#include <iostream>
using namespace std;

int main()
{
    int m, n;

    cout << "Enter number of Rows: ";
    cin >> n;

    cout << "Enter number of Columns: ";
    cin >> m;

    int chosenOne;
    cout << "Enter chosenOne: ";
    cin >> chosenOne;

    int arr[n][m];

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == chosenOne)
            {
                flag = true;
                break;
            }
        }
    }

    if (flag)
    {
        cout << "Through out the Heaven and Earth I alone am the chosen ONE";
    }
    else
    {
        cout << "Bithch you'rn not";
    }

    return 0;
}
