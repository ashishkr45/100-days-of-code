#include <iostream>
#include <cstring>
using namespace std;

void reverse(char str[]);
void toPrint(char str[]);

int main()
{
    char str[50];
    cout << "Enter a word: ";
    cin >> str;

    reverse(str);

    return 0;
}

void reverse(char str[])
{
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    toPrint(str);
    return;
}

void toPrint(char str[])
{
    cout << "Converted the string: " << str << endl;
}