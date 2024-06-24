#include <iostream>
using namespace std;

/*
time complecity of this algorithm is O(n)
cuz, this array will run n times.
*/

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

    int key;
    cout << "Enter the key: ";
    cin >> key;

    bool KeyThere = true;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Index of key: " << i << endl;
            bool KeyThere = true;
            break;
        }
        else
        {
            bool KeyThere = false;
        }
    }

    if (KeyThere)
    {
        cout << "Enter key dosen't exist";
    }

    return 0;
}