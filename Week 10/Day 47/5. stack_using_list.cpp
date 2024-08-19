#include <iostream>
#include <string>

using namespace std;

template <class t>
class Node
{
public:
    t data;
    Node *next;

    Node(t val)
    {
        data = val;
        next = NULL;
    }
};

template <class D>
class Stack
{
    Node<D> *head;

public:
    Stack()
    {
        head = NULL;
    }

    void push(D val)
    {
        // push_front implementation000
        Node<D> *newNode = new Node<D>(val);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop()
    {
        // implementing pop_front()
        Node<D> *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    D top()
    {
        return head->data;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void print()
    {
        while (!isEmpty())
        {
            cout << top() << " ";
            pop();
        }
        return;
    }
};

int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();

    cout << endl;
    Stack<string> str;
    str.push("Damm");
    str.push("this's");
    str.push("Working");

    str.print();

    return 0;
}