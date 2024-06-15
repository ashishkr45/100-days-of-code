#include <iostream>
using namespace std;

void factorial(int n);
void print(int n);

int main()
{

    int n;
    cout << "Enter a number: ";
    cin >> n;

    factorial(n);

    return 0;
}

void factorial(int n)
{
    int temp = 1;
    for (int i = 1; i <= n; i++)
    {
        temp *= i;
        print(temp);
    }
    return;
}

void print(int n)
{
    cout << n << endl;
    return;
}