#include <iostream>
using namespace std;

int pow(int x, int n) // time complexity of this O(n)
{
    if (n == 0) // base case of x^0 = 1
    {
        return 1;
    }
    // Recursive case: x^n = x * x^(n-1)
    return x * pow(x, n - 1);
}

int halfApporach(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }

    int halfPow = halfApporach(x, n / 2);
    int halfSq = halfPow * halfPow;

    if (n % 2 != 0) // odd
    {
        return x * halfSq;
    }
    return halfSq;
}

int main()
{
    cout << halfApporach(2, 10);

    return 0;
}