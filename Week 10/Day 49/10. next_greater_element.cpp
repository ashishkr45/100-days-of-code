#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void nextGreater(vector<int> nums, vector<int> greater) // O(n)
{
    stack<int> greatoro;
    int idx = nums.size() - 1;
    greater[idx] = -1;
    greatoro.push(nums[idx]);

    for (idx -= 1; idx >= 0; idx--)
    {
        int currentNums = nums[idx];
        while (!greatoro.empty() && currentNums >= greatoro.top())
        {
            greatoro.pop();
        }

        if (greatoro.empty())
            greater[idx] = -1;
        else
            greater[idx] = greatoro.top();

        greatoro.push(nums[idx]);
    }

    for (int i = 0; i < (int)greater.size(); i++)
    {
        cout << greater[i] << " ";
    }
    cout << endl;
    return;
}

int main()
{
    vector<int> nums = {6, 8, 0, 1, 3};
    vector<int> greater(nums.size(), 0);

    nextGreater(nums, greater);

    return 0;
}
