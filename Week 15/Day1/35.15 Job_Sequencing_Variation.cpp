#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job
{
    int idx;
    int deadline;
    int profit;

    Job(int idx, int deadline, int profit)
    {
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

bool compair(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second > p2.second;
}

int maxPorfit(vector<pair<int, int>> pairs)
{
    vector<Job> jobs;
    for (int i = 0; i < (int)pairs.size(); i++)
    {
        jobs.emplace_back(i, pairs[i].first, pairs[i].second);
    }

    sort(jobs.begin(), jobs.end(), [](Job &a, Job &b) // lambda function
         { return a.profit > b.profit; });            // decending order based on the profit;

    cout << "Selection Job: " << jobs[0].idx << endl;
    int profit = jobs[0].profit;
    int safeDeadline = 2;

    for (int i = 0; i < (int)jobs.size(); i++)
    {
        if (jobs[i].deadline >= safeDeadline)
        {
            cout << "Selection Job: " << jobs[i].idx << endl;
            profit += jobs[i].profit;
            safeDeadline++;
        }
    }
    return profit;
}

int main()
{
    int n = 4;
    vector<pair<int, int>> jobs(n, make_pair(0, 0));
    jobs[0] = make_pair(4, 20);
    jobs[1] = make_pair(1, 10);
    jobs[2] = make_pair(1, 40);
    jobs[3] = make_pair(1, 30);

    cout << "Maximum Profit earned: " << maxPorfit(jobs) << endl;
    return 0;
}