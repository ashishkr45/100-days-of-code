#include <iostream>
using namespace std;

void decPrint(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    decPrint(n - 1);
}

void assPrint(int n)
{
    if (n == 0)
        return;

    assPrint(n - 1);
    cout << n << " ";
}

int main()
{

    int num;
    cout << "Enter a number: ";
    cin >> num;

    decPrint(num);
    return 0;
}