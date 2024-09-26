#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> a = {4, 1, 8, 7};
    vector<int> b = {2, 3, 6, 5};

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int abs_Diff = 0;

    for (int i = 0; i < (int)a.size(); i++)
    {
        abs_Diff += abs(a[i] - b[i]);
    }

    cout << "Min Abs Diff: " << abs_Diff << endl;

    return 0;
}