0000000 #include<iostream> using namespace std;

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

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop_front()
    {
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    }
};

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

bool isCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cout << "Cycle found\n";
            return true;
        }
    }
    cout << "Cycle not found\n";
    return false;
}

void removeCycle(Node *head)
{
    /*detecting cycle*/
    Node *slow = head;
    Node *fast = head;
    bool cycle = false;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cout << "Cycle found\n";
            cycle = true;
            break;
        }
    }

    if (!cycle)
    {
        cout << "Cycle dosen't exist\n";
        return;
    }

    slow = head;
    /*special case: tail is connected to head and
    solw and fast meet at head*/
    if (slow == head)
    {
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = nullptr; // cycle is removed
    }
    else
    {
        Node *prev = fast;
        while (slow != fast)
        {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }
        prev->next = nullptr; // cycle ends here
    }
}

int main()
{
    List linked;
    linked.push_front(8);
    linked.push_front(2);
    linked.push_front(3);
    linked.push_front(4);
    linked.push_front(5);

    /*creating a loop*/
    linked.tail->next = linked.head;

    // isCycle(linked.head);
    removeCycle(linked.head);
    printLL(linked.head);

    return 0;
}