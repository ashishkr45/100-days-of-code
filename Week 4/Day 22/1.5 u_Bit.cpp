#include <iostream>
using namespace std;

void update(int num, int i, int v);

int main()
{
    int n, i, v;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Enter the index: ";
    cin >> i;
    cout << "Enter the value(0, 1): ";
    cin >> v;

    update(n, i, v);

    return 0;
}

void update(int num, int i, int v)
{
    /*clearing the ith bit*/
    int mask = ~(1 << i);
    num = num & mask;

    /*setting the value*/
    num = num | (v << i);

    cout << "Updated number: " << num << endl;

    return;
}
