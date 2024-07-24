#include <iostream>
#include <string>

using namespace std;

void movingElement(string str, char x, string ans, int i, int count)
{
    if ((int)str.size() == i && count == 0)
    {
        cout << ans << endl;
        return;
    }

    if ((int)str.size() == i)
    {
        // Append the character x count times to ans
        ans.append(count, x);
        cout << ans << endl;
        return;
    }

    if (str[i] == x)
    {
        movingElement(str, x, ans, i + 1, count + 1);
    }
    else
    {
        movingElement(str, x, ans + str[i], i + 1, count);
    }
}

int main()
{
    string str;
    char x;
    cout << "Enter a string: ";
    cin >> str;

    cout << "Enter the element X: ";
    cin >> x;

    int i = 0, count = 0;

    movingElement(str, x, "", i, count);

    return 0;
}
