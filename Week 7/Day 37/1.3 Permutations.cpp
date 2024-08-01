/*Total number of permuatations of a string is n!
    where n is the number of elemets in the array*/
#include <iostream>
#include <string>

using namespace std;

void permutations(string str, string ans)
{
    if (str.size() == 0)
    {
        cout << ans << "\t";
        return;
    }

    for (int i = 0; i < (int)str.size(); i++)
    {
        char ch = str[i];
        permutations(str.substr(0, i) + str.substr(i + 1, str.size() - i - 1), ans + ch);
    }
}

int main()
{
    string str;
    cin >> str;

    permutations(str, "");
}