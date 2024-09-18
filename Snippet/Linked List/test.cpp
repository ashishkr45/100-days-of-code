#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int itr = 0;
    vector<char> finals;

    vector<bool> check(256, false);

    for (int i = 0; i < str.size(); i++)
    {
        if (!check[str[i]])
        {
            finals.push_back(str[i]);
        }
        else
        {
            check[str[i] - '0'] = true;
        }
    }

    for (int i = 0; i < finals.size(); i++)
    {
        cout << finals[i];
    }

    return 0;
}