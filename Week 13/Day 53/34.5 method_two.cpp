#include <iostream>
#include <stack>

using namespace std;

class Queue
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int val)
    {
    }

    void pop()
    {
    }

    int front()
    {
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(6988);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}