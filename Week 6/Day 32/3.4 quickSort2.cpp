#include <iostream>

using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int si, int ei)
{
    int i = si - 1, pivot = arr[ei];
    for (int j = si; j < ei; j++)
    {
        if (arr[j] > pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    i++;
    swap(arr[i], arr[ei]);
    return i;
}

void QS(int arr[], int si, int ei)
{
    if (si >= ei)
        return;

    int pivotIdx = partition(arr, si, ei);

    QS(arr, si, pivotIdx - 1);
    QS(arr, pivotIdx + 1, ei);
}

int main()
{
    int n;
    cout << "Enter the Length: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    QS(arr, 0, n - 1);
    print(arr, n);

    return 0;
}
