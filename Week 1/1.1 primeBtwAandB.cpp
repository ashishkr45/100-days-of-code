#include <iostream>
#include <math.h>
using namespace std;

void primeCheck(int a, int b);

void print(int a);

int main()
{

    int a, b;
    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    primeCheck(a, b);

    return 0;
}

void primeCheck(int a, int b)
{
    for (int i = a; i <= b; i++)
    {
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                break;
            }
            else
            {
                print(i);
                break;
            }
        }
    }
    return;
}

void print(int a)
{
    cout << a << endl;
    return;
}