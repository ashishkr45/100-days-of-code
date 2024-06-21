// First Repeating Element

/*
Problem:
Given an array arr[] of size N. The task is to find the first repeating element in the array of
integers, i.e., an element that occurs more than once and whose index of first occurrence is
smallest.

Constraints:
1 <= N <= 10^6
O <= Ai <= 10^6

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    const int N = 1e6 + 2; // we put const cuz nothing will be able to change it.
    int idx[n];

    for (int i = 0; i < N; i++)
    {
        idx[i] = -1;
    }

    int minIndex = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (idx[a[i]] != -1)
        {
            minIndex = min(minIndex, idx[a[i]]);
        }
        else
        {
            idx[a[i]] = i;
        }
    }

    if (minIndex == INT_MAX)
    {
        cout << "Minium Index not found" << endl;
    }
    else
    {
        cout << "Minium Index: " << minIndex + 1 << endl;
    }

    return 0;
}