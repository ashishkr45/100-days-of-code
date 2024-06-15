#include <iostream>
using namespace std;

int combinations(int n, int r);
int factorial(int a);

int main()
{

    int n, r;
    cout << "Enter total number of items (n): ";
    cin >> n;

    cout << "Enter number of item to chosen (r)";
    cin >> r;

    cout << "The result is: " << combinations(n, r) << endl;

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