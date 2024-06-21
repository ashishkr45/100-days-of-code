/*
Question:
cyana is given the number of visitors at her local theme park on N consecutive days. The number of visitors on the i-th day is Vi A day is record breaking if it satisfies both conditions:
    - The number of visitors on the day is strictly larger than the number of visitors on each of the previous days.
    - Either it is the last day, or the number of visitors on the day is strictly larger than the
number of visitors on the following day.

note: that the very first day could be a record breaking day!
*/

/*
Brute Force:
1. Iterate over all the elements and check if it is record breaking day or not.
Note: To check if a[i] is a record breaking day, we have to iterate over a[O], a[l],....,a[i-1]
Time complexity for this operation: O(n)

Overall Time Complexity: O(n^2)

Optimised Approach:
Intuition: If we can optimise step (1), then we can optimise our overall solution.
For step (1): We need to check if a[i] > { a[i-l], a[i-2),..., a[O] }, which is same as a[i] > max(a[i-l], a[i-2],...,a[0])

For this, we will keep a variable mx, which will store the maximum value till a[i]. Then we just need to check,
            a[i] > mx
            a[i] > a[i+1], {if i+l < n}
and update mx, mx = max(mx, a[i])

So step 1 time complexity reduces to O(1) .
Overall time complexity: O(n)
*/

// This question was asked in google Kick Start.

/*
aka what we need to is that,
1. we need to make a max variable in which we'll track the max var through the itration.
2. we'll check if the current element is greator then the next element
(a[i] > a[i+1])
3. as well as we'll also check if it's greator then the max var i.e.
a[i] > { a[i-l], a[i-2),..., a[O] } cuz, its being updated at each itration wherever it finds a larger element(just like the program 3.7 maxTill_i)
*/

#include <iostream>
using namespace std;

// int maxTill_I(int arr[], int n);
void recordBreaking(int arr[], int n);

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

    if (n == 1)
    {
        cout << "1" << endl;
        return 0;
    }

    recordBreaking(arr, n);

    return 0;
}

void recordBreaking(int arr[], int n)
{
    int mx = -1;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mx && arr[i] > arr[i + 1])
        {
            cout << "Record Breaking Day for i = " << i << endl;
            ans++;
        }
        mx = max(mx, arr[i]);
    }

    cout << "Total number of Record Braking day: " << ans << endl;
}
