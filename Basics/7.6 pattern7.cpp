#include <iostream>
using namespace std;

/*
a fucking butterfly
*             *
* *         * *
* * *     * * *
* * * * * * * *
* * * * * * * *
* * *     * * *
* *         * *
*             *

*/

int main()
{

    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            if (j <= i || j >= 9 - i)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    for (int i = 4; i >= 1; i--)
    {
        for (int j = 8; j >= 1; j--)
        {
            if (j <= i || j >= 9 - i)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}