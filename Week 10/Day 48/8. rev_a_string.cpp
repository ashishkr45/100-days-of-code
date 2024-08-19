#include <iostream>
#include <stack>
#include <string>

using namespace std;

string reverseSTR(string str)
{
    string ans;
    stack<char> s;

    for (int i = 0; i < (int)str.size(); i++)
    {
        s.push(str[i]);
    }

    while (!s.empty())
    {
        char top = s.top();
        ans += top;
        s.pop();
    }

    return ans;
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    cout << "Reversed: " << reverseSTR(str);

    return 0;
}