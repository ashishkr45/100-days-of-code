#include <iostream>
using namespace std;

void counter()
{
    int n = 0;
    cout << n++ << " ";
    return;
}

void staticCounter()
{
    static int n = 0;
    cout << n++ << " ";
    return;
}

class staticExample
{
public:
    static int n; // we'll have to just declear here and initilise it outeside of the class
};

int staticExample::n = 1;

class nonStaticExample
{
public:
    int n = 1;
};

int main()
{
    cout << "This part is without static" << endl;
    counter();
    counter();
    counter();
    cout << endl;
    cout << "This part is with static" << endl;
    staticCounter();
    staticCounter();
    staticCounter();
    cout << endl;
    cout << "This part is without static in class" << endl;
    nonStaticExample e1;
    nonStaticExample e2;
    nonStaticExample e3;
    cout << e1.n++ << " ";
    cout << e2.n++ << " ";
    cout << e3.n++ << " ";
    cout << endl;
    cout << "This part is with static in class" << endl;
    staticExample s1;
    staticExample s2;
    staticExample s3;
    cout << s1.n++ << " ";
    cout << s2.n++ << " ";
    cout << s3.n++ << " ";

    return 0;
}