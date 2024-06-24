#include <iostream>
using namespace std;

int binaryDeci(int n);

int main()
{

    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "The number in binary: " << binaryDeci(n) << endl;

    return 0;
}

int binaryDeci(int n)
{

    int ans = 0;
    int x = 1;

    while (n > 0)
    {
        int y = n % 10;
        ans += x * y;
        x *= 2;
        n /= 10;
    }

    return ans;
}