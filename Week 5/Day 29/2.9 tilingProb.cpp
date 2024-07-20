#include <iostream>
using namespace std;

int tiling(int n)
{
    if (n == 0 || n == 1)
        return 1;

    int way1 = tiling(n - 1); // here putting the tiles vertically
    /*the remaining area will be 2*(n-1)*/

    int way2 = tiling(n - 2); // here putting the tiles horizontally
    /*remaining area after this will be 2*(n-2)*/

    return way1 + way2; // adding both ways to get the total
}

int main()
{
    int n;
    cout << "enter a number: ";
    cin >> n;

    cout << "Tiling Problem " << n << " is = " << tiling(n);
}