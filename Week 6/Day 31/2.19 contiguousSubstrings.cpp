/*We are given a string S, we need to find the count of all contiguous substrings starting and ending with the same character.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> subString;

// Function to print valid subsequences
void print()
{
    for (const string &s : subString)
    {
        cout << s << endl;
    }
}

void Subsequence(string str, int idx, string ans)
{
    if (idx == (int)str.length())
    {
        // Check if the subsequence is not empty and starts and ends with the same character
        if (!ans.empty() && ans.front() == ans.back())
        {
            subString.push_back(ans);
        }
        return;
    }

    // including the current char
    Subsequence(str, idx + 1, ans + str[idx]);

    // not including the current char
    Subsequence(str, idx + 1, ans);
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    Subsequence(str, 0, "");
    print();

    return 0;
}