#include <iostream>
#include <vector>

using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int si, int ei)
{
    vector<int> temp;
    int mid = si + (ei - si) / 2;

    int i = si;      // this'll point to the left-half of the array
    int j = mid + 1; // this's pointing to the rigth half of the array after the mid

    while (i <= mid && j <= ei)
    {
        if (arr[i] >= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= ei)
    {
        temp.push_back(arr[j++]);
    }

    for (int i = si, x = 0; i <= ei; i++)
    {
        arr[i] = temp[x++];
    }
}

void reverseMergeSort(int arr[], int si, int ei)
{
    if (si >= ei)
        return;

    int mid = si + (ei - si) / 2;
    reverseMergeSort(arr, si, mid);
    reverseMergeSort(arr, mid + 1, ei);

    merge(arr, si, ei);
}

int main()
{
    int n;
    cout << "Enter the Length: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    reverseMergeSort(arr, 0, n - 1);

    print(arr, n);

    return 0;
}
