#include <iostream>
#include <vector>
using namespace std;

int firstOccur(const vector<int> vec, int i, int target)
/*using const cuz, avoid copying the entire vector and to
ensure the function does not modify the vector.*/
{
    if (vec[i] == target)
    {
        return i;
    }
    if (i >= (int)vec.size())
    {
        return -1;
    }

    return firstOccur(vec, i + 1, target);
}

int main()
{
    int n, target;
    cout << "Enter the size of vector: ";
    cin >> n;

    cout << "Enter the number: ";
    cin >> target;

    vector<int> vec(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    int index = lastOccur(vec, (int)vec.size() - 1, target); // Capture the return value
    if (index != -1)
    {
        cout << "First occurrence of " << target << " is at index " << index + 1 << endl;
    }
    else
    {
        cout << target << " not found in the vector" << endl;
    }

    return 0;
}