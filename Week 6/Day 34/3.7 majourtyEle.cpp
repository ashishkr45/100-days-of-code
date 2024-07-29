#include <iostream>
#include <vector>

using namespace std;

int theNum(vector<int> nums)
{
}

void majortiy(vector<int> &nums, int turn)
{
    if (turn == nums.size() - 1)
    {
        return;
    }
    vector<int> ans = {0};
    ans[nums[turn]] += 1;
}

void mergeSort(vector<int> &nums, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;
    mergeSort(nums, start, mid); // left-half
    mergeSort(nums, mid, end);   // right-half

    merge(nums, 0);
}

int main()
{
    int n;
    cout << "Enter the size of the Input: ";
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    strMergeSort(nums, 0, nums.size() - 1);
    print(names);
    return 0;
}