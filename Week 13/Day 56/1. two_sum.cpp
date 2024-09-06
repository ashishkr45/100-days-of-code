#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void print(vector<int> ans)
    {
        for (int i = 0; i < (int)ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    void twoSum(vector<int> &nums, int target)
    {
        vector<int> ans;
        int i = 0;
        int j = nums.size() - 1;

        while (i < j)
        {
            if (nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
                print(ans); // Output the indices if target sum is found
                return;     // Stop after finding the first pair
            }
            else if (nums[i] + nums[j] < target)
            {
                ++i; // Move left pointer to the right if the sum is less than the target
            }
            else
            {
                --j; // Move right pointer to the left if the sum is greater than the target
            }
        }
    }
};

int main()
{
    vector<int> sum = {3, 2, 4};
    Solution s;
    s.twoSum(sum, 6);
    return 0;
}
