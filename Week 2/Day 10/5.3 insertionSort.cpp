#include <iostream>
#include <climits>
using namespace std;

void insertionSort(int *arr, int n);
void printArr(int *arr, int n);
void swap(int *a, int *b);

int main()
{

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    insertionSort(arr, n);

    return 0;
}

void insertionSort(int *arr, int n)
{
    /*tracking unsorted array*/
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int previous = i - 1;

        while (previous >= 0 && arr[previous] > current)
        {
            swap(arr[previous], arr[previous + 1]);
            previous--;
        }
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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}