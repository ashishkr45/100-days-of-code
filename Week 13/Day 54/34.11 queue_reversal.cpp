#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void printQueue(queue<int> q2)
{
    while (!q2.empty())
    {
        cout << q2.front() << " ";
        q2.pop();
    }
}

void reversal(queue<int> q)
{
    stack<int> stk;

    while (!q.empty())
    {
        stk.push(q.front());
        q.pop();
    }

    while (!stk.empty())
    {
        q.push(stk.top());
        stk.pop();
    }
    printQueue(q);
    return;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reversal(q);
}