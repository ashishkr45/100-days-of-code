#include <iostream>
using namespace std;

int binarySearch(int arr[], int st, int ed, int key)
{
    if (st > ed)
    {
        return -1;
    }

    int mid = (st + ed) / 2;
    if (arr[mid] == key)
    {
        return mid + 1;
    }
    else if (arr[mid] > key)
    {
        return binarySearch(arr, st, mid - 1, key);
    }
    else
    {
        return binarySearch(arr, mid + 1, ed, key);
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

    cout << "ans: " << binarySearch(arr, 0, n, m) << endl;

    return 0;
}