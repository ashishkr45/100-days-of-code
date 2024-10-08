#include <iostream>
#include <string>
using namespace std;

int balancedStringSplit(string s)
{
    int Rcount = 0;
    int Lcount = 0;
    int ans = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == 'L')
        {
            Lcount++;
        }
        else
        {
            Rcount++;
        }

        if (Lcount == Rcount && Lcount != 0 && Rcount != 0)
        {
            ans++;
            Lcount = 0;
            Rcount = 0;
        }
    }
    return ans;
}

int main()
{
    string s = "RLRLRLRLRLLRRLLRRRLRLLRRRLLRLRLRLLRRLLRLRRLLRRLLRLRLRRLRRLLRRLLRLRLRLRRLLRLL";
    cout << "String size: " << s.size() << endl;
    cout << "Total balanced String: " << balancedStringSplit(s);
}