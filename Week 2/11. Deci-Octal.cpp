#include <iostream>
using namespace std;

int converttoOCTAL(int n);

int main()
{

    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Conversion to Decimal is: " << endl;
    cout << converttoOCTAL(n);

    return 0;
}

int converttoOCTAL(int n)
{
    int x = 1;
    int ans = 0;

    while (x <= n)
        x *= 8;
    x /= 8;

    while (x > 0)
    {
        int last = n / x;
        n -= last * x;
        x /= 8;
        ans = ans * 10 + last;
    }
    return ans;
}