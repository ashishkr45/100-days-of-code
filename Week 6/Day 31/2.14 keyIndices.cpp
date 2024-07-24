#include <iostream>
using namespace std;

void Indices(int arr[], int key, int n, int i)
{
    if (i == n)
    {
        return;
    }
    if (arr[i] == key)
    {
        cout << i + 1 << " ";
        Indices(arr, key, n, i + 1);
    }
    else
    {
        Indices(arr, key, n, i + 1);
    }
}

int main()
{
    int n, m;
    cout << "Enter the length: ";
    cin >> n;

    int arr[n];
    cout << "Enter the numbers: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the key: ";
    cin >> m;

    Indices(arr, m, n, 0);

    return 0;
}