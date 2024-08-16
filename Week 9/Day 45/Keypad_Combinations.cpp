#include <iostream>
#include <vector>
#include <string>

using namespace std;

void combi(int pos, string digi, vector<vector<char>> comb, string ans, int length)
{
    if (pos == length)
    {
        cout << ans << "\t";
    }
    else
    {
        vector<char> layer = comb[digi[pos] - '0' - 2];
        for (int i = 0; i < (int)layer.size(); i++)
        {
            combi(pos + 1, digi, comb, ans + layer[i], length);
        }
    }
}

void digiExt(vector<vector<char>> comb, string digit)
{
    int len = digit.length();
    if (len == 0)
    {
        cout << "" << endl;
        return;
    }

    string ans = "";
    combi(0, digit, comb, ans, len);
}

int main()
{
    vector<vector<char>> combination = {{'a', 'b', 'c'},
                                        {'d', 'e', 'f'},
                                        {'g', 'h', 'i'},
                                        {'j', 'k', 'l'},
                                        {'m', 'n', 'o'},
                                        {'p', 'q', 'r', 's'},
                                        {'t', 'u', 'v'},
                                        {'w', 'x', 'y', 'z'}};

    string digit;
    cout << "Enter the digit: ";
    cin >> digit;

    digiExt(combination, digit);
    return 0;
}