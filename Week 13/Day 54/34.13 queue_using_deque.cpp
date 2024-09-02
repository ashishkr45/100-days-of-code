#include <iostream>
#include <deque>

using namespace std;

class Queue
{
private:
    deque<int> queue;

public:
    void push(int val)
    {
        queue.push_back(val);
        return;
    }

    void pop()
    {
        queue.pop_front();
    }

    int front()
    {
        return queue.front();
    }

    bool empty()
    {
        return queue.empty();
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

    cout << "Without poping" << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}