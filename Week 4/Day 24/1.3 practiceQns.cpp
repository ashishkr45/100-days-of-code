/*
Create a User class with properties : id (private), username(public) & password (private).
Its id should be initialized in a parameterised constructor.
It should have a Getter & Setter for password.
*/

#include <iostream>
#include <string>
using namespace std;

class User
{
private:
    int id;
    string password;

public:
    string username;
    User(int id)
    {
        this->id = id;
    }

    void setPass(string password)
    {
        this->password = password;
    }

    string getPass()
    {
        return password;
    }
};

int main()
{
    User user1(101);
    user1.username = "Lucifer";
    user1.setPass("sdf8fe4");

    cout << "Username: " << user1.username << endl;
    cout << "Password: " << user1.getPass() << endl;

    return 0;
}