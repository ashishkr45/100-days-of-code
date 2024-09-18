#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next = NULL;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void push_back(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

void DelDupli(Node *head)
{
    Node *temp = head;
    if (temp->next == NULL)
    {
        return;
    }

    while (temp != NULL && temp->next != NULL)
    {
        Node *check = temp;
        while (check->next != NULL)
        {
            if (check->next->data == temp->data)
            {
                Node *duplicate = check->next;
                check->next = check->next->next;
                delete duplicate;
            }
            else
            {
                check = check->next;
            }
        }
        temp = temp->next;
    }
    return;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return;
}

int main()
{
    Node *head = NULL;

    push_back(head, 10);
    push_back(head, 10);
    push_back(head, 20);
    push_back(head, 130);
    push_back(head, 60);
    push_back(head, 60);
    push_back(head, 20);
    push_back(head, 69);
    push_back(head, 10);
    push_back(head, 30);

    printList(head);
    cout << endl;
    DelDupli(head);
    printList(head);

    return 0;
}