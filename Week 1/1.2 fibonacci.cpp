#include <iostream>
using namespace std;

void fib(int n);
void print(int n);

int main()
{

    int n;
    cout << "Enter a number: ";
    cin >> n;

    fib(n);

    return 0;
}

void fib(int n)
{
    int a1 = 0;
    int a2 = 1;
    int him;

    for (int i = 0; i < n; i++)
    {
        print(a1);
        print(a2);
        cout<<endl;
        him = a1 + a2;
        a1 = a2;
        a2 = him;
    }
    return;
}

void print(int n)
{
    cout << n<<" ";
    return;
}