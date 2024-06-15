#include <iostream>
using namespace std;

// numeric pyrimid0000

int main()
{

    for (int i = 1; i <= 4; i++) // row loop
    {
        for (int j = 1; j <= 4 - i; j++) // space loop
        {
            cout << "  ";
        }
        for (int k = 1; k <= 2 * i - 1; k++) // numbers loop
        {
            cout << "* ";
        }
        cout << endl;
    }
    for (int i = 4; i >= 1; i--) // row loop
    {
        for (int j = 1; j <= 4 - i; j++) // space loop
        {
            cout << "  ";
        }
        for (int k = 1; k <= 2 * i - 1; k++) // numbers loop
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}