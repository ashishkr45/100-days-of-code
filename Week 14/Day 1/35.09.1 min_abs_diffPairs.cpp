#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

void makePair(const vector<int> &a, const vector<int> &b)
{
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int diff = INT_MAX;
    for (int i = 0; i < (int)a.size(); i++)
    {
        int CurrDiff = 0;
        for (int j = 0; j < (int)b.size(); j++)
        {
            int diff_the_2nd = abs(a[i] - b[j]);
            CurrDiff += diff_the_2nd;
        }
        if (diff > CurrDiff)
        {
            diff = CurrDiff;
        }
    }
    cout << diff;
}

int main()
{
    vector<int> a = {1, 5, 1};
    vector<int> b = {5, 5, 5};

    makePair(a, b);

    return 0;
}