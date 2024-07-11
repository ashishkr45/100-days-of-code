#include <iostream>
using namespace std;

void clearI(int n, int i);

int main()
{
    int n, i;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Enter the index: ";
    cin >> i;

    clearI(n, i);

    return 0;
}

void clearI(int n, int i)
{
    cout << (n & ((~0) << i)) << endl;
    return;
}