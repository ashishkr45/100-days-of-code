/*
Counting Sort: gennerally used when the range(difference between max and min element) of the elemnts ls low and whe we are dealing wth positive numbers.

in this we'll make another array which will store the frrequency of the elements in the array.

the frequency array indexes will give the value(frequency) of the numbers stored at that index.

*/

#include <iostream>
#include <climits>
using namespace std;

void countingSort(int *arr, int n);
void printArr(int *arr, int n);
int arrMin(int *arr, int n);
int arrMax(int *arr, int n);

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

    countingSort(arr, n);

    return 0;
}

void countingSort(int *arr, int n)
{
    int minVal = arrMin(arr, n);
    int maxVal = arrMax(arr, n);
    int range = maxVal - minVal + 1;

    int freq[range] = {0};

    /* Filling the frequency array with the frequency of the elements in arr */
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (int i = 0, j = 0; i < range; i++)
    {
        while (freq[i] > 0)
        {
            arr[j++] = i;
            freq[i]--;
        }
    }
    printArr(arr, n);
}

void printArr(int *arr, int n)
{

    cout << "Sorted array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    return;
}

int arrMin(int *arr, int n)
{
    int minVal = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        minVal = min(minVal, arr[i]);
    }
    return minVal;
}

int arrMax(int *arr, int n)
{
    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxVal = max(maxVal, arr[i]);
    }
    return maxVal;
}