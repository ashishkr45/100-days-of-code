/*
Question 1 : Use the following sorting algorithms to sort an array in DESCENDING order :

a. Bubble Sort
b. Selection Sort
c. Insertion Sort
d. Counting Sort

You can use this array as an example : [3, 6, 2, 1, 8, 7, 4, 5, 3, 1]
*/

#include <iostream>
#include <climits>
using namespace std;

void bubbleSort(int *arr, int n);
void selectionSort(int *arr, int n);
void insertionSort(int *arr, int n);
void printArr(int *arr, int n);
void swap(int *a, int *b);

int main()
{
    int arr[] = {3, 6, 2, 1, 8, 7, 4, 5, 3, 1};
    int size = sizeof(arr) / sizeof(int);

    printArr(arr, size);
    cout << endl;

    insertionSort(arr, size);

    return 0;
}

void bubbleSort(int *arr, int n)
{
    /*tracking current element*/
    for (int i = 0; i < n - 1; i++)
    {
        /*replacing that with bigger element if it finds one*/
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "Sorted array: " << endl;
    printArr(arr, n);
}

void selectionSort(int *arr, int n)
{
    /*tracking/itrating throught the array*/
    for (int i = 0; i < n - 1; i++)
    {
        int max = i;
        /*finding the biggest element and replacing it with the first*/
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[max])
            {
                max = j;
            }
        }
        swap(arr[i], arr[max]);
    }
    cout << "Sorted array: " << endl;
    printArr(arr, n);
}

void insertionSort(int *arr, int n)
{
    /*tracking unsorted array*/
    for (int i = 1; i < n; i++)
    {
        int current = arr[i];
        int previous = i - 1;

        while (previous >= 0 && arr[previous] < current)
        {
            swap(arr[previous], arr[previous + 1]);
            previous--;
        }
    }
    cout << "Sorted array: " << endl;
    printArr(arr, n);
}

/*this'll print the arrays*/
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

/*simple two number swaping function.*/
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}