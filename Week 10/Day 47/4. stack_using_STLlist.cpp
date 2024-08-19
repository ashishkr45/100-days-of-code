#include <iostream>
#include <string>
#include <list>

using namespace std;

template <class D>
class Stack
{
    list<D> lst;

public:
    void push(D val)
    {
        lst.push_front(val);
    }

    void pop()
    {
        lst.pop_front();
    }

    D top()
    {
        return lst.front();
    }

    bool isEmpty()
    {
        return lst.size() == 0;
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