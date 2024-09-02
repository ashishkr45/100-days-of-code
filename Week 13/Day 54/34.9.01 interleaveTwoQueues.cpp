/*using three Queues*/
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
    return;
}

void interleave(queue<int> q1)
{
    int interleaveSize = q1.size() / 2;

    int count = 0;
    queue<int> q2;

    while (count < interleaveSize)
    {
        q2.push(q1.front());
        q1.pop();
        count++;
    }

    int counter = 0;
    queue<int> q3;
    while (counter < interleaveSize)
    {
        q3.push(q2.front());
        q2.pop();

        q3.push(q1.front());
        q1.pop();

        counter++;
    }

    printQueue(q3);
    return;
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