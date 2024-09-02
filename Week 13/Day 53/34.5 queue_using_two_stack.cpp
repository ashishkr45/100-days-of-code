#include <iostream>
#include <stack>
using namespace std;

class Queue
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int val) // O(n) will be it's time complexity
    {
        /*1. transfering the elem of s1 to s2*/
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        /*2. inserting the data at the end of the stack*/
        s1.push(val);

        /*3. again pushing the data of the s1 back to s1 from the s2*/
        /*so that the new elem is at the bottonm of the stack so, it follows the FIFO structure*/

        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop() // O(1)
    {
        s1.pop();
    }

    int front() // O(1)
    {
        return s1.top();
    }

    bool empty() // O(1)
    {
        return s1.empty();
    }
};

int main()
{
    Queue q; // creation of the objecte
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(6988);
    q.push(48);
    q.push(88);

    q.pop();

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}