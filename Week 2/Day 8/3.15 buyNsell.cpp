/*121. Best Time to Buy and Sell Stock*/
// LEETCODE

/*

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

*/

#include <iostream>
#include <climits>
using namespace std;

void maxProfit(int *prices, int n);

int main()
{
    int days;
    cout << "Enter number of Days: ";

    int prices[days];

    cout << "Enter the price of the stock for eachday: ";
    for (int i = 0; i < days; i++)
    {
        cin >> prices[i];
    }

    maxProfit(prices, days);

    return 0;
}

void maxPrices(int *prices, int n)
{
    int bestBuy[1000000];
    bestBuy[0] = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        bestBuy[i] = min(bestBuy[i - 1], prices[i - 1]);
    }
    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        int currentProfit = prices[i] - bestBuy[i];
        maxProfit = max(maxProfit, currentProfit);
    }

    cout << "Max Profit: " << maxProfit << endl;
}
