/*
Problem:
You are given an array arr[] of N integers including O. The task is to find the smallest
positive number missing from the array.
*/

#include <iostream>
using namespace std;

int main()
{

    int n;
    cout << "Enter array length: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    const int N = 1e6 + 2;
    bool check[N];

    for (int i = 0; i < N; i++)
    {
        check[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            check[arr[i]] = true;
        }
    }

    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        if (check[i] == false)
        {
            ans = i;
            break;
        }
    }

    cout << "Smallest missing +vs no: " << ans << endl;

    return 0;
}