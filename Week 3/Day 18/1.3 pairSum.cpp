/*Problem 167 #leetcode*/

#include <iostream>
#include <vector>
using namespace std;

void brutePairSum(int n, vector<int> vec, int sum);
void effPairSum(int n, vector<int> vec, int sum);
vector<int> twoSum(vector<int> &numbers, int target);

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

    int add;
    cout << "Enter the sum: ";
    cin >> add;

    effPairSum(n, vec, add);

    vector<int> ans = twoSum(vec, add);
    cout << "(" << ans[0] << ", " << ans[1] << ")";

    return 0;
}

void brutePairSum(int n, vector<int> vec, int sum)
{
    /*
    here since we're using nested loop so the time complexity will be O(n^2)
    */

    // brute force Method
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vec[i] + vec[j] == sum)
            {
                cout << "Pair found: (" << vec[i] << ", " << vec[j] << ")" << endl;
                return;
            }
            else
            {
                continue;
            }
        }
    }
    cout << "Pair not found" << endl;
    return;
}

void effPairSum(int n, vector<int> vec, int sum)
{

    int st = 0, ed = n - 1;

    while (st < ed)
    {
        int currentSum = vec[st] + vec[ed];

        if (currentSum < sum)
            4
            {
                st++; // Move the start index forward
                /*cuz, it's sorted in assending and to the right
                we'll be having bigger elemnts and since, currentSum
                is smaller that's why we're moving to the right*/
            }
        else if (currentSum > sum)
        {
            ed--; // Move the end index backward
            /*we're having smaller elements to the left so
            we're moving to left since currSum is bigger now*/
        }
        else // sum found!
        {
            cout << "Pair found: (" << vec[st] << ", " << vec[ed] << ")" << endl;
            return;
        }
    }
    cout << "Pair not found" << endl;
    return;
}

vector<int> twoSum(vector<int> &numbers, int target)
{
    int st = 0, ed = numbers.size() - 1;
    int currSum = 0;
    vector<int> ans;

    while (st < ed)
    {
        currSum = numbers[st] + numbers[ed];
        if (currSum > target)
        {
            ed--;
        }
        else if (currSum < target)
        {
            st++;
        }
        else
        {
            ans.push_back(st + 1);
            ans.push_back(ed + 1);
        }
    }
    return ans;
}
