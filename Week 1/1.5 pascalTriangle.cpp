#include <iostream>
using namespace std;

/*

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1

*/

int combinations(int n, int r);
int factorial(int a);

int main()
{
    int size;
    cout << "Enter the size of the triangle: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << combinations(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}

int combinations(int n, int r)
{
    int nCr = factorial(n) / (factorial(n - r) * factorial(r));
    return nCr;
}

int factorial(int a)
{
    int temp = 1;
    for (int i = 1; i <= a; i++)
    {
        temp *= i;
    }
    return temp;
}