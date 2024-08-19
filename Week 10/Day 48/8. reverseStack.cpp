#include <iostream>
#include <stack>

using namespace std;

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void pushAtBottom(stack<int> &stk, int num)
{
    if (stk.empty())
    {
        stk.push(num);
        return;
    }

    int temp = stk.top();
    stk.pop();
    pushAtBottom(stk, num);
    stk.push(temp);
}

void reverse(stack<int> &stk)
{
    if (stk.empty())
    {
        return;
    }
    int temp = stk.top();
    stk.pop();
    reverse(stk);
    pushAtBottom(stk, temp);
}

int main()
{
    stack<int> stk;
    stk.push(3);
    stk.push(2);
    stk.push(1);
    printStack(stk);

    reverse(stk);
    printStack(stk);

    return 0;
}