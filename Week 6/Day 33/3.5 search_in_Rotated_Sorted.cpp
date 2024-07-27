// Leetcode 33
/*solve these 81, 153, 1752*/
#include <iostream>

using namespace std;

void modBinary(int arr[], int si, int ei, int target)
{
    int mid = si + (ei - si) / 2;

    if (arr[mid] == target)
    {
        cout << "Target Fount! index: " << mid << endl;
        return;
    }

    if (arr[si] <= arr[mid]) // Line 1
    {
        if (arr[si] <= target && arr[mid] >= target) // left-half
        {
            modBinary(arr, si, mid - 1, target); // right-half
        }
        else
        {
            modBinary(arr, mid + 1, ei, target);
        }
    }
    else
    {
        if (arr[mid] <= target && arr[ei] >= target)
        {
            modBinary(arr, mid + 1, ei, target);
        }
        else
        {
            modBinary(arr, si, mid - 1, target);
        }
    }
}

int main()
{
    int n, m;
    cout << "Enter the lenght of the array: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the target: ";
    cin >> m;

    modBinary(arr, 0, n - 1, m);

    return 0;
}