#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compair(pair<double, int> p1, pair<double, int> p2)
{
    return p1.first > p2.first; // decending based on ratio
}

void fractionalKnapsack(vector<int> val, vector<int> weight, int W)
{
    vector<pair<double, int>> ratio((int)val.size(), make_pair(0.0, 0)); // pair(ratio, idx) => (double, int)
    int ans = 0;
    for (int i = 0; i < (int)val.size(); i++)
    {
        double r = val[i] / (double)weight[i]; // making the ratios
        ratio[i] = make_pair(r, i);            // making the pair of the ratios and the index
        // to keep track of'em
    }

    sort(ratio.begin(), ratio.end(), compair); // O(nlogn)

    for (int i = 0; i < (int)val.size(); i++)
    {
        int idx = ratio[i].second;
        if (weight[idx] <= W)
        {
            ans += val[idx];
            W -= weight[i];
        }
        else
        {
            ans += ratio[i].first * W;
            W = 0;
            break;
        }
    }
    cout << "Max value: " << ans;
    return;
}

int main()
{
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int W = 50; // weight limit;

    fractionalKnapsack(val, wt, W);
    return 0;
};