#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Print the linked list
void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Insert at the beginning of the linked list
Node *insertBegin(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

// Insert at the end of the linked list
Node *insertEnd(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
        return temp;

    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

// Insert at a specific position in the linked list
Node *insertAtPos(Node *head, int pos, int x)
{
    if (pos == 1)
    {
        return insertBegin(head, x);
    }

    Node *temp = new Node(x);
    Node *curr = head;

    for (int i = 1; i < pos - 1 && curr != NULL; i++)
    {
        curr = curr->next;
    }

    if (curr == NULL)
        return head; // Position out of bounds

    temp->next = curr->next;
    curr->next = temp;
    return head;
}

// Delete from the beginning of the linked list
Node *deleteBegin(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Delete from the end of the linked list
Node *deleteEnd(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }

    delete curr->next;
    curr->next = NULL;
    return head;
}

// Delete at a specific position in the linked list
Node *deleteAtPos(Node *head, int pos)
{
    if (head == NULL)
        return NULL;
    if (pos == 1)
        return deleteBegin(head);

    Node *curr = head;

    for (int i = 1; i < pos - 1 && curr->next != NULL; i++)
    {
        curr = curr->next;
    }

    if (curr->next == NULL)
        return head; // Position out of bounds

    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;
    return head;
}

int main()
{
    Node *head = NULL;

    // Insert at the beginning
    head = insertBegin(head, 30);
    head = insertBegin(head, 20);
    head = insertBegin(head, 10);
    cout << "After inserting at the beginning: ";
    printlist(head);

    // Insert at the end
    head = insertEnd(head, 40);
    cout << "After inserting at the end: ";
    printlist(head);

    // Insert at position 3
    head = insertAtPos(head, 3, 25);
    cout << "After inserting 25 at position 3: ";
    printlist(head);

    // Delete from the beginning
    head = deleteBegin(head);
    cout << "After deleting from the beginning: ";
    printlist(head);

    // Delete from the end
    head = deleteEnd(head);
    cout << "After deleting from the end: ";
    printlist(head);

    // Delete from position 2
    head = deleteAtPos(head, 2);
    cout << "After deleting from position 2: ";
    printlist(head);

    return 0;
}