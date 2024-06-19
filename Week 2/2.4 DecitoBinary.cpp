#include <iostream>
using namespace std;

int convertDecimal(int n);

int main()
{

    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Conversion to Decimal is: " << endl;
    cout << convertDecimal(n);

    return 0;
}

int convertDecimal(int n)
{
    int x = 1;
    int ans = 0;

    while (x <= n)
        x *= 2;
    x /= 2;

    while (x > 0)
    {
        int last = n / x;
        n -= last * x;
        x /= 2;
        ans = ans * 10 + last;
    }
    return ans;
}