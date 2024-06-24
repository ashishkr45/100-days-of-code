#include <iostream>
using namespace std;

int main()
{
    int a, b, c, max;

    cout << "Enter 1st number: ";
    cin >> a;

    cout << "Enter 2nd number: ";
    cin >> b;

    cout << "Enter 3rd number: ";
    cin >> c;

    max = a;

    if (b > max)
    {
        max = b;
    }
    if (c > max)
    {
        max = c;
    }
    cout << "The largest number: " << max << endl;

    return 0;
}