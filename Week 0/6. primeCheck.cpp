// 3.1 Break and continew statements
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (n == 1)
    {
        cout << "The number is a Prime.";
    }

    for (int i = 2; i < n - 1; i++)
    {
        if (n % i == 0)
        {
            cout << "The number is not a Prime.";
            break;
        }
        else
        {
            cout << "The number is a Prime.";
            break;
        }
    }

    return 0;
}