#include <iostream>
using namespace std;

void binSort(int *arr, int n);
void printArr(int *arr, int n);
void swap(int *a, int *b);

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

    binSort(arr, n);

    return 0;
}

void binSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
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