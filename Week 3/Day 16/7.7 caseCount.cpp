#include <iostream>
#include <string>
using namespace std;

void counter(string str);

int main()
{
    string str, anaStr;

    cout << "Enter the original string: ";
    cin >> str;

    counter(str);

    return 0;
}

void counter(string str)
{
    int lower = 0, upper = 0;

    for (int i = 0; i < (int)str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            lower++;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            upper++;
        }
        else
        {
            cout << "Wrong Input! at index: " << i << endl;
            return;
        }
    }
    cout << "Total number of UpperCase: " << upper << endl;
    cout << "Total number of LowerCase: " << lower << endl;

    return;
}