#include <iostream>
#include <deque>

using namespace std;

class Stack
{
private:
    deque<int> stack;

public:
    void push(int val)
    {
        stack.push_back(val);
        return;
    }

    void pop()
    {
        stack.pop_back();
        return;
    }

    int top()
    {
        return stack.back();
    }

    bool empty()
    {
        return stack.empty();
    }
};

int main()
{
    Stack s;

    for (int i = 0; i < 6; i++)
    {
        s.push(i);
    }

    for (int i = 0; i < 6; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}