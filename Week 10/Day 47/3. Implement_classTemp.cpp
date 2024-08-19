#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class D>

class Stack
{
    vector<D> stack;

public:
    void push(D val)
    {
        stack.push_back(val);
    }

    bool empty()
    {
        return stack.size() == 0;
    }

    void pop()
    {
        if (empty())
        {
            cout << "Stack is Empty\n";
            return;
        }

        stack.pop_back();
    }

    D top() // Change return type to D
    {
        if (empty())
        {
            cout << "Stack is Empty\n";
            // Return a default-constructed D object when the stack is empty.
            return D();
        }
        return stack[stack.size() - 1];
    }

    void print()
    {
        while (!empty())
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