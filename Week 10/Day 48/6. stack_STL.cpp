#include <iostream>
#include <stack>

using namespace std;

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    printStack(s);

    cout << endl;
    stack<string> str;
    str.push("Damm");
    str.push("this's");
    str.push("Working");

    return 0;
}