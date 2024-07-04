#include <iostream>
#include <cstring>
using namespace std;

void toUpper(char str[]);
void toLower(char str[]);
void toPrint(char str[]);

int main()
{
    char str[50];
    cout << "Enter a word: ";
    cin >> str;

    toUpper(str);
    toLower(str);

    return 0;
}

void toUpper(char str[])
{
    for (int i = 0; i < (int)strlen(str); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            int pos = str[i] - 'a';
            str[i] = 'A' + pos;
        }
    }
    toPrint(str);
    return;
}

void toLower(char str[])
{
    for (int i = 0; i < (int)strlen(str); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            int pos = str[i] - 'A';
            str[i] = 'a' + pos;
        }
    }
    toPrint(str);
    return;
}

void toPrint(char str[])
{
    cout << "Converted the string: " << str << endl;
}