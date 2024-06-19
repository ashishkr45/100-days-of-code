#include <iostream>
using namespace std;

int octalDeci(int n);

int main()
{

    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "The number in binary: " << octalDeci(n) << endl;

    return 0;
}

int octalDeci(int n)
{

    int ans = 0;
    int x = 1;

    while (n > 0)
    {
        int y = n % 10;
        ans += x * y;
        x *= 8;
        n /= 10;
    }

    return ans;
}
