#include <iostream>
using namespace std;

bool isSorted(int arr[], int n, int i)
{
    if (i == n - 1)
        return true;

    if (arr[i] > arr[i + 1])
        return false;

    // Recurse for the next element
    return isSorted(arr, n, i + 1);
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (isSorted(arr, n, 0))
        cout << "The array is sorted." << endl;
    else
        cout << "The array is not sorted." << endl;

    return 0;
}
