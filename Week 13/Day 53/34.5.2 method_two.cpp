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
        s1.push(val);
    }

    void pop()
    {
        /*moving the elem's to the other stack*/
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int front()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        return s2.top();

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
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
    q.push(48);
    q.push(88);

    q.pop();

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}