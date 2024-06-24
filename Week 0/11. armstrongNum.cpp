#include <iostream>
// #include <math.h>
using namespace std;

int main()
{

    int Orgnum, temp;
    int num;
    int armstrong = 0;

    cout << "Enter a number: ";
    cin >> num;

    Orgnum = num;
    // creating a second copy of the number using it in loop.

    while (num > 0)
    {
        temp = num % 10;
        int dude = temp * temp * temp;
        armstrong += dude;
        num = num / 10;
    }

    if (armstrong == Orgnum)
    {
        cout << "Entered number is Armstrong" << endl;
    }
    else // dont understand what's wrong here
    {
        cout << "Enterd number is not Armstrong" << endl;
        // cout << Orgnum << endl;
        // cout << armstrong << endl;
    }

    return 0;
}