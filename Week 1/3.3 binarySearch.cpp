#include <iostream>
using namespace std;

/*
-for implementation of binary serach all the elements of the array should be sorted

-we'll start the serching from the mid element of the array, we'll compair that mid element with the if its less and more
- then we'll find the second mid-element from initial mid-element till last element and compare to the key.
-and we'll follow this process unitl we find the key.

-this way the size get reducing first it was n then n/2 then n/4 and so on

-time complexity: O(log n with base 2)

*/
int binarySearch(int arr[], int n, int key);

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

    int key;
    cout << "Enter the key: ";
    cin >> key;

    cout << "Index of the key: " << binarySearch(arr, n, key) << endl;

    return 0;
}

int binarySearch(int arr[], int n, int key)
{
    int s = 0;
    int e = n;
    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}
00