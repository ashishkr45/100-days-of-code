#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(const vector<string> &arr)
{
    for (const auto &str : arr)
    {
        cout << str << " ";
    }
    cout << endl;
}

void mergeStr(vector<string> &names, int si, int ei)
{
    int mid = si + (ei - si) / 2;

    vector<string> ans;
    int i = si, j = mid + 1;

    while (i <= mid && j <= ei)
    {
        if (names[i] < names[j])
        {
            ans.push_back(names[i++]);
        }
        else
        {
            ans.push_back(names[j++]);
        }
    }

    while (i <= mid)
    {
        ans.push_back(names[i++]);
    }
    while (j <= ei)
    {
        ans.push_back(names[j++]);
    }

    for (int i = si, x = 0; i <= ei; i++)
    {
        names[i] = ans[x++];
    }
}

void strMergeSort(vector<string> &names, int si, int ei)
{
    if (si >= ei)
        return;

    int mid = si + (ei - si) / 2;

    strMergeSort(names, si, mid);
    strMergeSort(names, mid + 1, ei);

    mergeStr(names, si, ei);
}

int main()
{
    int n;
    cout << "Enter the size of the Input: ";
    cin >> n;
    vector<string> names(n); // Resizing the vector to the input size
    for (int i = 0; i < n; i++)
    {
        cin >> names[i];
    }

    strMergeSort(names, 0, names.size() - 1);
    print(names);
    return 0;
}
