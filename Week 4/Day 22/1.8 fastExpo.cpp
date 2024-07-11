#include <iostream>
using namespace std;

void factExpo(int x, int n)
{
    int ans = 1;

    while (n > 0)
    {
        if (n & 1)
        {
            ans = ans * x;
        }
        x = x * x;
        n = n >> 1;
    }

    cout << "Expo of num: " << ans << endl;
    return;
}

int main()
{

    int num, pow;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Enter the power: ";
    cin >> pow;

    factExpo(num, pow);

    return 0;
}