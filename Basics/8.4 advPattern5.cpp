#include <iostream>
using namespace std;

// numeric pyrimid

int main()
{

    for (int i = 1; i <= 5; i++) // row loop
    {
        int j;
        for (j = 1; j <= 5 - i; j++) // space loop
        {
            cout << "  ";
        }
        int k = i;
        for (; j <= 5; j++) // numbers loop
        {
            cout << k-- << " ";
        }
        // don't understand from here!!!
        k = 2;
        for (; j <= 5 + i - 1; j++)
        {
            cout << k++ << " ";
        }

        cout << endl;
    }

    return 0;
}