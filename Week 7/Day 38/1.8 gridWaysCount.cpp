#include <iostream>
using namespace std;

int fact(int n)
{
    if (n <= 1) // Base case
        return 1;
    return n * fact(n - 1);
}

int countWays(int row, int col)
{
    return fact(row - 1 + col - 1) / (fact(row - 1) * fact(col - 1));
}

int main()
{
    int n, m;
    cout << "Enter the Rows: ";
    cin >> n;
    cout << "Enter the Columns: ";
    cin >> m;

    cout << "Count of total ways: " << countWays(n, m) << endl;

    return 0;
}