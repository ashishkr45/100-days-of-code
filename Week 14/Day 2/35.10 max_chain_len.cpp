#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compair(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second; // assending
}

int maxChainLen(vector<pair<int, int>> pairs)
{
    sort(pairs.begin(), pairs.end(), compair);
    int ans = 1;
    int currEnd = pairs[0].second;

    for (int i = 1; i < (int)pairs.size(); i++)
    {
        if (pairs[i].first > currEnd)
        {
            ans++;
            currEnd = pairs[i].second;
        }
    }
    return ans;
}

int main()
{
    int n = 5; // number of pairs we making
    vector<pair<int, int>> pairs(n, make_pair(0, 0));
    pairs[0] = make_pair(5, 24);
    pairs[1] = make_pair(39, 60);
    pairs[2] = make_pair(5, 28);
    pairs[3] = make_pair(27, 40);
    pairs[4] = make_pair(50, 90);

    cout << "Max chain length: " << maxChainLen(pairs);
}