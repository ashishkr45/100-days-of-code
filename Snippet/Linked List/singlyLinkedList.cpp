#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

void printList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    return;
}

Node *insertBegin(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == nullptr)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    return head;
}

Node *insertEnd(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == nullptr)
    {
        head = temp;
    }
    else
    {
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = temp;
        temp->next = nullptr;
    }
    return head;
}

Node *insertAtPos(Node *head, int data, int pos)
{
    Node *temp = new Node(data);
    Node *curr = head;

    for (int i = 0; i < pos; i++)
    {
        curr = curr->next;
    }

    temp->next = curr->next;
    curr->next = temp;

    return head;
}

Node *delAtFront(Node *head)
{
    Node *curr = head;
    if (head->next == nullptr)
    {
        return nullptr;
    }
    head = head->next;
    delete curr;
    return head;
}

Node *dalAtBack(Node *head)
{
    Node *curr = head;
    if (head->next == nullptr)
        return nullptr;

    if (head == nullptr)
        return nullptr;

    while (curr->next->next != nullptr)
        curr = curr->next;

    delete curr->next;
    curr->next = nullptr;

    return head;
}

Node *dalAtPos(Node *head, int pos)
{
    if (head == nullptr)
        return nullptr;
    if (pos == 1)
        return delAtFront(head);

    Node *curr = head;
    for (int i = 0; i < pos - 1 && curr != nullptr; i++)
        curr = curr->next;

    Node *temp = curr->next;
    curr->next = curr->next->next;
    delete temp;

    return head;
}

int main()
{
    Node *head = new Node(10);
    Node *elem1 = new Node(20);
    Node *elem2 = new Node(30);
    Node *elem3 = new Node(40);

    head->next = elem1;
    elem1->next = elem2;
    elem2->next = elem3;
    elem3->next = nullptr;
    cout << "Initial elements\n";
    printList(head);

    // Inserting at the begin
    head = insertBegin(head, 3);
    head = insertBegin(head, 2);
    head = insertBegin(head, 1);
    cout << "Inserting at the begin\n";
    printList(head);

    // Inserting at the end
    head = insertEnd(head, 50);
    head = insertEnd(head, 60);
    cout << "Inserting at the end\n";
    printList(head);

    // insertion at a position
    cout << "insertion at any position\n";
    head = insertAtPos(head, 69, 5);
    printList(head);

    // deletion at the begin
    head = delAtFront(head);
    head = delAtFront(head);
    cout << "deletion at the begin\n";
    printList(head);

    // deletion at the back
    head = dalAtBack(head);
    cout << "deletion at the back\n";
    printList(head);

    // deletion at position
    head = dalAtPos(head, 6);
    cout << "deletion at position\n";
    printList(head);

    return 0;
}