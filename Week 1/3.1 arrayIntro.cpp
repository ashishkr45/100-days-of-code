#include <iostream>
#include <climits>
// we are using this hedder file to using INT_MIN/MAX, which gives the smallest/largest value possible in INT.

using namespace std;

int main()
{

    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    int arr[n];
    // like i have a doubt here wount we using DMA(Dynamic Memory allocation to initilise a variable with user defined variable values??)

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maxNum = INT_MIN;
    int minNum = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        // if (arr[i] > max)
        // {
        //     max = arr[i];
        // }
        maxNum = max(maxNum, arr[i]);

        // if (arr[i] < min)
        // {
        //     min = arr[i];
        // }
        minNum = min(minNum, arr[i]);

        /* max() and min() are built in functions.
         */
    }

    cout << "Maximim number: " << maxNum << endl;
    cout << "Minimum number: " << minNum << endl;

    return 0;
}