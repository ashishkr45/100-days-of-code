#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void stockSpan(vector<int> &stock, vector<int> &span) // Pass vectors by reference
{
    stack<int> s;
    s.push(0);
    span[0] = 1;

    for (int i = 1; i < (int)stock.size(); i++) // Start loop from 1
    {
        int currentPrice = stock[i];
        while (!s.empty() && currentPrice >= stock[s.top()])
        {
            s.pop();
        }
        if (s.empty())
        {
            span[i] = i + 1;
        }
        else
        {
            int prevHigh = s.top();
            span[i] = i - prevHigh;
        }
    }

    for (int i = 0; i < (int)span.size(); i++)
    {
        cout << span[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> stock = {100, 80, 60, 70, 60, 85, 100};
    vector<int> span(stock.size(), 0);

    stockSpan(stock, span);

    return 0;
}
