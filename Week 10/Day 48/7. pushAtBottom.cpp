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

void pushAtBottom(stack<int> &stk, int num) // Pass by reference
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

int main()
{

    stack<int> stk;
    stk.push(3);
    stk.push(2);
    stk.push(1);

    int num;
    cout << "Enter the number: ";
    cin >> num;

    pushAtBottom(stk, num);

    // Print the stack after pushing at the bottom
    printStack(stk);

    return 0;
}