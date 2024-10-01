#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};

    int funds;
    cout << "Enter Funds: ";
    cin >> funds;

    int ans = 0;

    cout << "Coins used: ";
    for (int i = (int)coins.size() - 1; i >= 0 && funds > 0; i--)
    {
        if (funds >= coins[i])
        {
            ans += funds / coins[i];
            funds = funds % coins[i];
            cout << coins[i] << " ";
        }
    }
    cout << endl;
    cout << "Tol. coins: " << ans << endl;
    return 0;
}