#include <iostream>
#include <string>

using namespace std;

void reverse(string str, int idx)
{
    if (idx == (int)str.size())
    {
        cout << str[str.size() - idx];
        return;
    }
    else
    {
        cout << str[str.size() - idx];
        reverse(str, idx + 1);
    }
}

int main()
{

    string str;
    cout << "Enter a string: ";
    cin >> str;

    reverse(str, 0);

    return 0;
}