#include <iostream>
using namespace std;

int main()
{

    for (int i = 0; i <= 5; i++)
    {
        for (int j = 1; j <= 5 - i; j++)
        {
            cout << "  ";
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            char alpha = (char)j + 64;
            cout << alpha << " ";
            alpha = 0;
        }
        cout << endl;
    }

    for (int i = 4; i >= 1; i--) // row loop
    {
        for (int j = 1; j <= 5 - i; j++) // space loop
        {
            cout << "  ";
        }
        for (int k = 1; k <= 2 * i - 1; k++) // numbers loop
        {
            char alpha = (char)k + 64;
            cout << alpha << " ";
            alpha = 0;
        }
        cout << endl;
    }

    return 0;
}