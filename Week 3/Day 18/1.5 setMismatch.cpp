/*645. Set Mismatch*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> ErrorNums(vector<int> &nums);
vector<int> findErrorNums(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 1; i < (int)nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
        {
            ans.push_back(nums[i - 1]);
            nums[i]++;
            ans.push_back(nums[i]);
        }
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the size of vector: ";
    cin >> n;

    vector<int> vec(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    vector<int> ans = ErrorNums(vec);
    cout << "(" << ans[0] << ", " << ans[1] << ")";

    return 0;
}

vector<int> ErrorNums(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();
    vector<bool> isPresent(n + 1, false);
    for (int i = 0; i < n; i++)
    {
        if (isPresent[nums[i]])
        {
            ans.push_back(nums[i]);
        }
        isPresent[nums[i]] = true;
    }
    for (int i = 1; i < (int)isPresent.size(); i++)
    {
        if (!isPresent[i])
        {
            ans.push_back(i);
            break;
        }
    }
    return ans;
}