#include <iostream>
using namespace std;

void evenOdd(int n);

int main()
{

    int n;
    cout << "Enter a number: ";
    cin >> n;
    evenOdd(n);

    return 0;
}

void evenOdd(int n)
{
    if (!(n & 1))
    {
        cout << "Even" << endl;
        return;
    }
    else
    {
        cout << "Odd" << endl;
        return;
    }
    return;
}