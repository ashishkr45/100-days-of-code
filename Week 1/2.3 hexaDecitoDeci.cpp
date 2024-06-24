#include <bits/stdc++.h>
// we are ususing this cuz this includes all the libraryes we need.
using namespace std;

int hexadecimalToDecimal(string n);

int main()
{
    string n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "The number in decimal: " << hexadecimalToDecimal(n) << endl;

    return 0;
}

int hexadecimalToDecimal(string n)
{
    int ans = 0; // Initialize result
    int x = 1;   // Initialize base value to 1, i.e., 16^0

    int s = n.size();

    for (int i = s - 1; i >= 0; i--)
    {
        if (n[i] >= '0' && n[i] <= '9')
        {
            ans += x * (n[i] - '0');
        }
        else if (n[i] >= 'A' && n[i] <= 'F')
        {
            ans += x * (n[i] - 'A' + 10);
        }
        x *= 16; // Move to the next higher power of 16
    }

    return ans;
}
