#include <iostream>
using namespace std;

class Node
{
public:
    float data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // ~Node()
    // {
    //     if (next != NULL)
    //     {
    //         delete next;
    //         next = NULL;
    //     }
    // }
};

class Queue
{
    Node *head;
    Node *tail;

public:
    Queue()
    {
        head = tail = NULL;
    }

    // ~List()
    // {
    //     if (head != NULL)
    //     {
    //         delete head;
    //         head = NULL;
    //     }
    // }

    void push(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop()
    {
        if (Empty())
        {
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    int front()
    {
        if (Empty())
        {
            return -1;
        }
        return head->data;
    }

    bool Empty()
    {
        return head == NULL;
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
    while (!q.Empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}