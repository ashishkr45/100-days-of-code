#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void makePair(vector<int> a, vector<int> b)
{
    int diff = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int CurrDiff = 0;
        for (int j = 0; j < a.size(); j++)
        {
            int diff_the_2nd = abs(a[i] - b[i]);
            CurrDiff += diff_the_2nd;
        }
        if (CurrDiff < diff)
        {
            diff = CurrDiff;
        }
    }

    cout << diff;
}

int main()
{
    vector<int> a = {1, 2, 3};
    vector<int> b = {2, 1, 3};

    makePair(a, b);

    return 0;
}