#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int capacity;
    int currSize;

    int frontIndex, rear;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        currSize = 0;

        frontIndex = 0;
        rear = -1;
    }

    void push(int data)
    {
        if (currSize == capacity)
        {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = data;
        currSize++;
    }

    void pop()
    {
        if (empty())
        {
            cout << "Queue is empty\n";
            return;
        }
        frontIndex = (frontIndex + 1) % capacity;
        currSize--;
    }

    int front()
    {
        if (empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[frontIndex];
    }

    bool empty()
    {
        return currSize == 0;
    }

    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{
    Queue q(4);
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
