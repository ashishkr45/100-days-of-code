#include <iostream>
using namespace std;

bool pathagorial(int x, int y, int z);
int max(int a, int b);

int main()
{

    int a, b, c;
    cout << "Enter three numbers: ";
    cin >> a >> b >> c;

    if (pathagorial(a, b, c))
    {
        cout << "Pythagorial Triplet";
    }
    else
    {
        cout << "Not Pythagorial Triplet";
    }

    return 0;
}

bool pathagorial(int x, int y, int z)
{
    int a = max(x, max(y, z));
    int b, c;

    if (a == x)
    {
        b = y;
        c = z;
    }
    else if (a == y)
    {
        b = x;
        c = z;
    }
    else
    {
        b = x;
        c = y;
    }
    if (a * a == b * b + c * c)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}