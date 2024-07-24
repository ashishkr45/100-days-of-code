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
    // finding the index of the element

    if (flag[idx])
    {
        deduplication(str, ans, i + 1, flag);
    }
    else // initially the control will come here cuz, flag is false by default
    {
        flag[idx] = true;                              // marking the current element
        deduplication(str, ans + str[i], i + 1, flag); // adding the current elemet to the answer
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