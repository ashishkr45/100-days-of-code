#include <iostream>
using namespace std;

/*
number - binary - num-1 - num-1(in bin)     num & (num-1)
02  -   10      -   1   -   1           -        00
04  -   100     -   3   -   11          -       000
08  -   1000    -   7   -   111         -      0000
16  -   10000   -   15  -   1111        -     00000
32  -   100000  -   31  -   11111       -    000000

-in all of these there's only one set bit, rest all of them is zero
-if we take & of num and (num-1) we'll get 0
*/

int main()
{

    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (!(n & (n - 1)))
    {
        cout << "Power of two" << endl;
    }
    else
    {
        cout << "Not power of two" << endl;
    }

    return 0;
}