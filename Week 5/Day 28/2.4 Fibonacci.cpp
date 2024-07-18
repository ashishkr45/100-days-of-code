#include <iostream>
using namespace std;

long long int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n; // 0, 1
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Fibonacci number of " << num << " is = " << fibonacci(num) << endl;
}