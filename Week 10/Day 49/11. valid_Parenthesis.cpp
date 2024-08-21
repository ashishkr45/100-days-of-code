#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool valid(string str)
{
    stack<char> s;
    for (int i = 0; i < (int)str.size(); i++)
    {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') // openign
        {
            s.push(ch);
        }
        else
        {
            if (s.empty())
            {
                return false;
            }
            /*matching*/
            if ((s.top() == '[' && ch == ']') ||
                (s.top() == '(' && ch == ')') ||
                (s.top() == '{' && ch == '}'))
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }

    /*write this
    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }*/

    /*or this*/
    return s.empty();
}

int main()
{
    string str1 = {"{[()]}"};     // true
    string str2 = {"{[()))))]}"}; // false

    cout << valid(str1) << endl;
    cout << valid(str2) << endl;
    return 0;
}