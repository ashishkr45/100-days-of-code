#include <iostream>
#include <climits>
using namespace std;

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

    int max = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            cout << "Max till " << i << " is: " << max << endl;
        }
    }

    return 0;
}