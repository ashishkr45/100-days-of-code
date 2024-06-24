#include <iostream>
using namespace std;

void assSort(int arr[], int n);

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

    assSort(arr, n);

    return 0;
}

void assSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "Sorted in Assending Order: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}
