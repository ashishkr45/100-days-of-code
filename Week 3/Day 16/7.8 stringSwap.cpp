#include <iostream>
#include <string>
using namespace std;

void swap(string str, string strAna);

int main()
{
    string str, anaStr;

    cout << "Enter the original string: ";
    cin >> str;

    cout << "Enter the Anagram string: ";
    cin >> anaStr;

    swap(str, anaStr);

    return 0;
}

void swap(string str, string strAna)
{

    if (str.length() != strAna.length())
    {
        cout << "False" << endl;
    }

    for (int i = 0; i < (int)str.length() / 2; i++)
    {
        strAna[i] = strAna[strAna.length() - i];

        if (strAna == str)
        {
            cout << true << endl;
        }
        else
        {
            cout << "False" << endl;
            return;
        }
    }
    return;
}