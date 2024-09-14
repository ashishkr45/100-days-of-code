#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compair(pair<int, int> p1, pair<int, int> p2)
{
    // todo: sorting the value according to the end value accending
    return p1.second < p2.second;
    /*
        sorting the value according to the end value decending
        return p1.second > p2.second;

        todo sorting the value according to the first value accending
        return p1.first < p2.first;

        todo sorting the value according to the first value decending
        return p1.first > p2.first;
    */
}

int main()
{
    /*delclearing the vectors*/
    vector<int> start = {0, 1, 3};
    vector<int> end = {9, 2, 4};

    /*initilizing the pair*/
    vector<pair<int, int>> activity(3, make_pair(0, 0));

    /*inserting the values*/
    activity[0] = make_pair(start[0], end[0]);
    activity[1] = make_pair(start[1], end[1]);
    activity[2] = make_pair(start[2], end[2]);

    /*printing the pairs*/
    for (int i = 0; i < (int)activity.size(); i++)
    {
        cout << "A" << i << ": " << activity[i].first << ", " << activity[i].second << endl;
    }

    /*sorting the vectors*/
    sort(activity.begin(), activity.end(), compair);

    /*printing the activities again after they had been sorted*/
    cout << "---------SORTED---------" << endl;
    for (int i = 0; i < (int)activity.size(); i++)
    {
        cout << "A" << i << ": " << activity[i].first << ", " << activity[i].second << endl;
    }

    return 0;
}