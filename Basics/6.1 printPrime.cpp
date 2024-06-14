// printing all the numbers up to n whichever is prime

#include <iostream>
#include <cmath>
using namespace std;

// using math library cuz it is more efficient to check the divisiblity till the sqrt of the n

int main()
{

    int n;
    cout << "Enter a number: ";
    cin >> n;

    for (int i = 2; i < n; i++)
    {
        bool primeCheck = true;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                primeCheck = false;
                break;
            }
        }
        if (primeCheck)
        {
            cout << i << "\n";
        }
    }

    return 0;
}