#include <iostream>
using namespace std;

class Node
{
public:
    /*thie class'll be making the nodes of the Linked List*/
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }

    ~Node()
    {
        cout << "Destructor of Node for data: " << data << endl;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

class List
{
    Node *head; // this'll be the head ptr
    Node *tail; // this'll be the tail ptr

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    ~List()
    {
        cout << "Destructor of list\n";
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }

    void push_front(int val)
    {
        /*here we're using DMA since we want the value to stay sfter the function's end*/
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
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

    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void insert(int val, int pos)
    {
        Node *newNode = new Node(val); // insertion-node
        Node *temp = head;             // initially pointing at head

        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL) // handalling the corner cases
            {
                cout << "postion's INVALID \n";
                return;
            }

            temp = temp->next; // at each intation will point to the next node
        }
        // temp must be pointing at the node at the left of insertion-node

        /*now we'll connect the newNode with the node next to the one temp is pointing*/
        newNode->next = temp->next;

        /*now joining the connection the node which is left of insertion-node */
        temp->next = newNode;
    }
};

int main()
{
    List ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    // 1->2->3->4->NULL

    ll.push_back(8);
    ll.push_back(9);

    ll.insert(69, 5);
    ll.printList();

    return 0;
}