#include <iostream>
using namespace std;

class Stack
{
    int arr[56];
    int pushIdx = 0;

public:
    void push(int val)
    {
        arr[pushIdx] = val;
        pushIdx++;
    }

    int top()
    {
        return arr[pushIdx];
    }
};

int main()
{
    Stack s;
    s.push(5);
    s.push(4);
    s.push(3);

    return 0;
}