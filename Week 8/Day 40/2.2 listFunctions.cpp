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
    Node *head;
    Node *tail;

public:
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

    void print_List()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void pop_front()
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void push_front(int val)
    {
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

    void puch_ass(int val)
    {
        Node *Nothing = new Node(val);
        if (head == NULL)
        {
            head = tail = Nothing;
        }
        else
        {
            tail->next = Nothing;
            tail = Nothing;
        }
    }

    void pop_back()
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
        delete tail;
        tail = temp;
    }

    int searchItr(int key) // searchItrator
    {
        Node *temp = head;
        int idx = 0;
        while (temp->next != NULL)
        {
            if (temp->data == key)
            {
                return idx;
            }
            idx++;
            temp = temp->next;
        }
        return -1;
    }

    int helperRec(Node *temp, int key)
    {
        if (temp->next == NULL)
        {
            return -1;
        }
        if (temp->data == key)
        {
            return 0;
        }
        int idx = helperRec(temp->next, key);
        if (idx == -1)
        {
            return -1;
        }
        return idx + 1;
    }

    int searchRec(int key)
    {
        return helperRec(head, key);
    }

    void reverse()
    {
        Node *curr = head;
        Node *prev = NULL;

        while (curr != NULL)
        {
            Node *next = curr->next;
            curr->next = prev; // now it's pointing the privious element(reverse order!!)

            /*updations for next itrations*/
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    int size()
    {
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void removeNth(int n)
    {
        Node *prev = head;
        /*here at the end of the loop we'll have the element prev of nth*/
        for (int i = 0; i < (size() - n - 1); i++)
        {
            prev = prev->next;
        }
        Node *toDel = prev->next;
        cout << "Element which is deleted: " << toDel->data << endl;

        prev->next = prev->next->next;
    }
};

int main()
{
    List L1;
    L1.push_front(45);
    L1.push_front(96);
    L1.push_front(69);
    L1.push_front(11);

    L1.puch_ass(3);
    L1.puch_ass(2);
    L1.puch_ass(1);
    L1.print_List();

    L1.removeNth(3);
    L1.print_List();

    return 0;
}