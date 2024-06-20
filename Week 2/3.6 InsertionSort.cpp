#include <iostream>
using namespace std;

/*
Insert an element from unsorted
array to its correct position in
sorted array
*/

void insertionSort(int arr[], int n);
void printArr(int arr[], int n);

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

        insertionSort(arr, n);

    return 0;
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
    printArr(arr, n);
}

void printArr(int arr[], int n)
{

    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}