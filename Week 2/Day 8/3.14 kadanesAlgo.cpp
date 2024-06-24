#include <iostream>
#include <climits>
using namespace std;

void print(int n);
void maxSubarray(int *arr, int n);

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    maxSubarray(arr, n);

    return 0;
}

void print(int n)
{
    cout << n;
}

void maxSubarray(int *arr, int n)
{
    /*Kadane's Algorithm*/
    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];
        maxSum = max(maxSum, currentSum);
        if (currentSum <= 0)
            currentSum = 0;
    }
    print(maxSum);
}