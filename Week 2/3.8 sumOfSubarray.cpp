#include <iostream>
using namespace std;

void addSubArray(int arr[], int n);

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

    addSubArray(arr, n);

    return 0;
}

void addSubArray(int arr[], int n)
{
    int subSum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            subSum += arr[j];
            cout << subSum << endl;
        }
    }
}