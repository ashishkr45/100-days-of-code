#include <iostream>
using namespace std;

int main()
{
    cout << "Enter count of you sentence: ";
    int n;
    cin >> n;
    cin.ignore();

    char str[100];
    cout << "Enter a sentence: ";
    cin.getline(str, n);
    cin.ignore();
    // normaly in c++ while inputing a string if a white space come the next sting will be stored in next veaiable.

    // we are putting this cuz to clear the buffer(after this part only the input will be stored in next var.).
    int maxLen = 0;
    int currenLen = 0;
    int i = 0;

    while (1)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            if (currenLen > maxLen)
            {
                maxLen = currenLen;
            }
            currenLen = 0;
        }
        else
        {
            currenLen++;
        }

        if (str[i] == '\0')
        {
            break;
        }
        i++;
    }

    cout << "The largest word length is: " << maxLen << endl;

    return 0;
}