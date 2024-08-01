/*Total number of subsets of a string is 2^n
    where n is the number of elemets in the array*/
#include <iostream>
#include <string>

using namespace std;

void subSets(string str, string ans)
{
    if (str.size() == 0)
    {
        cout << ans << "\t";
        return;
    }

    char a = str[0];
    subSets(str.substr(1, str.size() - 1), ans + a); // yes
    subSets(str.substr(1, str.size() - 1), ans);     // no
}

int main()
{
    string str;
    cin >> str;

    subSets(str, " ");
}