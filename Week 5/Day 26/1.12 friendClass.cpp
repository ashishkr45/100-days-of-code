#include <iostream>
#include <string>
using namespace std;

class A
{
private:
    string privateData = "Can_access_me?";
    friend class B;
    friend void getPrivate(A &obj);
};

/*this'll be the friend class*/
class B // now B will have the access of the private data of A
{
public:
    void getprivate(A &obj)
    {
        cout << obj.privateData << endl;
    }
};

void getPrivate(A &obj)
{
    cout << obj.privateData << endl;
}

int main()
{

    A ob1;
    B ob2;

    ob2.getprivate(ob1);
    /*this'll not work until ans unless we make B a friend of A since the string is private*/

    return 0;
}