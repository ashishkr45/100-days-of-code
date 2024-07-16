#include <iostream>
using namespace std;

class Check
{
public:
    Check()
    {
        cout << "constructor..\n";
    } // created the constructor to check when the object is created

    ~Check()
    {
        cout << "destructor..\n";
    } // creating the destructor well tell us when the object will be deleated
};

int main()
{
    cout << "Program starting\n";
    int a = 0;
    if (a == 0)
    {
        static Check ch1;
        // Check c1;
        /*is w
        e didn't used the static keyword the object should be deleted here itself*/
    }

    cout << "Program ending..\n";

    /*here after compiling the above statment and befor the return statement then the object is deleted.*/

    return 0;
}