/*217. Contains Duplicate*/
// LEETCODE

#include <iostream>
using namespace std;

bool containsDuplicate(int *arr, int n);

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    cout << "Enter the elements with space: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    if (containsDuplicate(arr, size))
    {
        cout << "Array contains duplicates" << endl;
    }
    else
    {
        cout << "Array does not contain duplicates" << endl;
    }

    return 0;
}

bool containsDuplicate(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                return true;
            }
        }
    }
    return false;
}