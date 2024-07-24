#include <iostream>

using namespace std;

int partitioning(int arr[], int si, int ei)
{
    int i = si - 1; // this'll help in positioning elements & pivot
    int pivot = arr[ei];

    for (int j = si; j < ei; j++) // start from si instead of 0
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[ei]);
    return i;
}

void quickSort(int arr[], int si, int ei)
{
    if (si >= ei)
        return; // base-case

    int pivotIdx = partitioning(arr, si, ei);

    quickSort(arr, si, pivotIdx - 1); // left-half
    quickSort(arr, pivotIdx + 1, ei); // right-half
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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

    quickSort(arr, 0, n - 1);
    print(arr, n);

    return 0;
}
