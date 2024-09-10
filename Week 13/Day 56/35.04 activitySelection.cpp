#include <iostream>
#include <vector>

using namespace std;

int maxAct(vector<int> start, vector<int> end)
{
    // sort on the basis of end-time
    // select act1
    cout << "Selecting Activity 0\n";
    int count = 1;
    int currEndTime = end[0];

    for (int i = 0; i < (int)start.size(); i++)
    {

        if (start[i] >= currEndTime)
        {
            cout << "Selecting Activity " << i << endl;
            count++;
            currEndTime = end[i];
        }
    }

    return count;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> End = {2, 4, 6, 7, 9, 9};

    cout << "Total number of Activities: " << maxAct(start, End) << endl;
}