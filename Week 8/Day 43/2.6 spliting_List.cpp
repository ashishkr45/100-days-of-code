#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }

    ~Node()
    {
        if (next != nullptr)
        {
            delete next;
            next = nullptr;
        }
    }
};

class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }
    ~List()
    {
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }

    void push_back(int val)
    {
        Node *temp = new Node(val);
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
};

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to split the linked list into two halves
Node *splitMid(Node *head)
{
    if (head == NULL || head->next == NULL) // Check if list is empty or has one node
        return head;

    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;

    // Move 'slow' by one step and 'fast' by two steps
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev != NULL)
    {
        prev->next = NULL; // Split the list into two halves
    }

    return slow; // Return the head of the second half
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head; // Base case: list is empty or has one node
    }

    Node *rightHead = splitMid(head); // Split the list into two halves

    Node *left = mergeSort(head);       // Recursively sort the left part
    Node *right = mergeSort(rightHead); // Recursively sort the right part

    // return merge(left, right); // Merge the sorted left and right parts
    printLL(left);
    printLL(right);
}

int main()
{
    List ll;
    ll.push_back(88);
    ll.push_back(45);
    ll.push_back(8);
    ll.push_back(1);
    ll.push_back(58);

    printLL(ll.head);

    mergeSort(ll.head);

    return 0;
}