#include <iostream>
#include <cstring>
using namespace std;

bool palindrom(char str[]);

int main()
{
    char str[50];
    cout << "Enter a word: ";
    cin >> str;

    if (palindrom(str))
    {
        cout << "Enterd string is Palindrom.";
    }
    else
    {
        cout << "Enterd string is not Palindrom.";
    }

    return 0;
}

bool palindrom(char str[])
{
    int st = 0, ed = strlen(str) - 1;
    while (st < ed)
    {
        if (str[st] != str[ed])
        {
            return false;
        }
        st++, ed--;
    }
    return true;
}
