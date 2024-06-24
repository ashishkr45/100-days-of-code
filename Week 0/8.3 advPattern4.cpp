#include <iostream>
using namespace std;

// numeric pyrimid

int main()
{

    for (int i = 1; i <= 5; i++) // row loop
    {
        for (int j = 1; j <= 5 - i; j++) // space loop
        {
            cout << " ";
        }
        for (int k = 1; k <= i; k++) // numbers loop
        {
            cout << k << " ";
        }
        cout << endl;
    }

    return 0;
}