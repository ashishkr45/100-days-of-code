#include <iostream>
#include <vector>

using namespace std;

void mergeSort(int arr[], int si, int ei);
void merge(int arr[], int si, int ei, int mid);
void print(int arr[], int n);

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

    mergeSort(arr, 0, n - 1);

    print(arr, n);

    return 0;
}

// this is the divide-step
void mergeSort(int arr[], int si, int ei) // time-complixity is O(n)
{
    if (si >= ei)
    {
        return;
    }
    int mid = si + (ei - si) / 2; // mid = (si + ei) / 2

    /*this is the divide-part*/
    mergeSort(arr, si, mid);     // left part of arr
    mergeSort(arr, mid + 1, ei); // right part of arr

    /*this is the conqure-part*/
    merge(arr, si, ei, mid);
}

// this is the conqure-step
void merge(int arr[], int si, int ei, int mid) // time-complixity is O(log n)
{
    vector<int> ans;
    int i = si, j = mid + 1;

    while (i <= mid && j <= ei)
    {
        if (arr[i] < arr[j]) // the smaller ones are added first
        {
            // the one which is added only it's pointer is increamented
            ans.push_back(arr[i++]);
        }
        else
        {
            ans.push_back(arr[j++]);
        }
    }

    /*this'll ensure there are no leftovers after the above array's work
    if there're these set of loops will add'em*/
    while (i <= mid)
    {
        ans.push_back(arr[i++]);
    }

    while (j <= ei)
    {
        ans.push_back(arr[j++]);
    }

    /*copying the vector elemets to the og array*/

    for (int i = si, x = 0; i <= ei; i++)
    /*we're not starting the loops by zero cuz, we don't know over
    we're itrating could be the smaller sub arrays */
    {
        arr[i] = ans[x++]; // x is itrating over ans & i over og-array
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}