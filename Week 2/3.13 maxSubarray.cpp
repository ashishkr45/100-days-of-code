#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter array length: ";
    cin >> n;

    int a[n];
    cout << "Enter array enement with spaces" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int maxSum = INT_MIN;
    /*

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += a[k];
                }
                maxSum = max(sum, maxSum);
            }
        }
        time complexity of this method is O(n^3)
    */

    /*Cumulative Sum approach*/
    int currentSum[n + 1];
    currentSum[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        currentSum[i] = currentSum[i - 1] + a[i - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
        {
            sum = currentSum[i] - currentSum[j];
            maxSum = max(sum, maxSum);
        }
    }

    cout << maxSum << endl;

    return 0;
}