/*
Things to look forward to in this question
    1. mergeSort in linked list
    2. Finding half/mid in a linked list
    3. How'll we merge two sorted linked list (could be asked as a separate question)
*/

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
        next = NULL;
    }
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
            next = NULL;
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

    void push_front(int val)
    {
        Node *temp = new Node(val);
        if (head == NULL)
        {
            head = tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
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

// Function to merge two sorted linked lists
Node *merge(Node *leftHead, Node *rightHead)
{
    Node *ans = NULL; // Head of the merged list

    if (leftHead == NULL)
        return rightHead;
    if (rightHead == NULL)
        return leftHead;

    // Compare data and merge nodes accordingly
    if (leftHead->data <= rightHead->data)
    {
        ans = leftHead;
        ans->next = merge(leftHead->next, rightHead);
    }
    else
    {
        ans = rightHead;
        ans->next = merge(leftHead, rightHead->next);
    }
    return ans;
}

// Function to sort the linked list using merge sort
Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head; // Base case: list is empty or has one node
    }

    Node *rightHead = splitMid(head); // Split the list into two halves

    Node *left = mergeSort(head);       // Recursively sort the left part
    Node *right = mergeSort(rightHead); // Recursively sort the right part

    return merge(left, right); // Merge the sorted left and right parts
}

// Function to print the linked list
void printLL(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    List ll;
    ll.push_front(45);
    ll.push_front(69);
    ll.push_front(49);
    ll.push_front(65);
    ll.push_front(5);

    cout << "Before sorting: \n";
    printLL(ll.head);

    cout << "After sorting: \n";
    ll.head = mergeSort(ll.head); // Sort the list
    printLL(ll.head);             // Print the sorted list

    return 0;
}
