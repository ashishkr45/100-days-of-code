#include <iostream>
#include <string>
using namespace std;

void deduplication(string str, string ans, int i, int flag[26])
{
    if (i == (int)str.size())
    {
        cout << "Ans: " << ans << endl;
        return;
    }

    int idx = (int)(str[i] - 'a');

    if (flag[idx])
    {
        deduplication(str, ans, i + 1, flag);
    }
    else
    {
        flag[idx] = true;
        deduplication(str, ans + str[i], i + 1, flag);
    }
}

int main()
{

    string word;
    cout << "Enter a string: ";
    cin >> word;

    string ans;

    int flag[26] = {false};

    deduplication(word, ans, 0, flag);

    return 0;
}