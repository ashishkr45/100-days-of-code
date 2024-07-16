#include <iostream>
using namespace std;

class Parent
{
public:
    virtual void show()
    {
        cout << "Huh! virtual functions" << endl;
    }
};

class Child : public Parent
{
public:
    void show()
    {
        cout << "Virtual output from Chile." << endl;
    }
};

int main()
{
    Child child1;
    Parent *ptr;
    ptr = &child1; // this is run-time binding;
    ptr->show();

    return 0;
}