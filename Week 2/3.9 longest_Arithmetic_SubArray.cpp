#include <iostream>
using namespace std;

// This question was asked in google Kick Start.

/*
we need to find longest arithmetic subarray* that contains at least two integers and the difference btw two consecutive integers must be equal.

*what is arithmetic subarray, for example,[9, 10], and [3, 3, 3] are arithmetic subarray cuz, the differene between all of the intergers are equal.

while [1, 3, 3, 7], [2, 1, 2], and [1, 2, 4] are not arithmetic arrays.

*/

/*
Approach:

    -Loop over the array and find the answer.

    Maintain the following variables:
    1. Previous Common Difference (pd)
    2. Current Arithmetic Subarray length (curr)
    3. Max arithmetic subarray length (ans)

*/

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

    int ans = 2;
    int pd = a[1] - a[0];
    int j = 2;
    int curr = 2;

    while (j < n)
    {
        if (pd == a[j] - a[j - 1])
        {
            curr++;
        }
        else
        {
            pd = a[j] - a[j - 1];
            curr = 2;
        }
        ans = max(ans, curr);
        j++;
    }

    cout << "longest arithmetic subarray: " << ans << endl;

    return 0;
}