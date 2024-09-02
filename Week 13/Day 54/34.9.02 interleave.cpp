#include <iostream>
#include <queue>

using namespace std;

void printQueue(queue<int> q2)
{
    while (!q2.empty())
    {
        cout << q2.front() << " ";
        q2.pop();
    }
}

void interleave(queue<int> &q)
{
    int size = q.size() / 2;

    queue<int> qNew;

    // Move the first half of q to qNew
    for (int i = 0; i < size; ++i)
    {
        qNew.push(q.front());
        q.pop();
    }

    // Interleave the two queues
    while (!qNew.empty())
    {
        q.push(qNew.front());
        qNew.pop();
        q.push(q.front());
        q.pop();
    }

    // Print the interleaved queue
    printQueue(q);
}

int main()
{
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    q1.push(6);
    q1.push(7);
    q1.push(8);
    q1.push(9);
    q1.push(10);

    interleave(q1);

    return 0;
}
