#include <iostream>

using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void changeArr(int arr[], int n, int i)
{
    if (i == n)
    {
        printArray(arr, n);
        return;
    }
    arr[i] = i + 1;
    changeArr(arr, n, i + 1);
    arr[i] -= 2; // this'll happen inthe backtracking part
}

int main()
{
    int n;
    cout << "Enter the size of the Input: ";
    cin >> n;
    int arr[n]; // Resizing the vector to the input size

    changeArr(arr, n, 0);
    cout << "Backtracked array: " << endl;

    printArray(arr, n);

    return 0;
}