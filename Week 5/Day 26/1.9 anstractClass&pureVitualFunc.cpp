#include <iostream>
#include <string>
using namespace std;

class Draw // now, this class is, Abstract class
{
public:
    /*virtual void draw() this is a virtual function*/

    virtual void draw() = 0; // this is a pure virtual function

    /*this is a unimplemented pure virtual function we;ve just deleared it
    not implemented it so noe output.*/
};

/*we'll use this abstract class to inheritate and make diff classes now*/

class Circle : public Draw
{
public:
    void draw()
    {
        cout << "Draw Circle\n";
    }
};

class Square : public Draw
{
public:
    void draw()
    {
        cout << "Draw Square\n";
    }
};

int main()
{

    Circle c1;
    c1.draw();

    Square sq1;
    sq1.draw();
    /*
        Draw shape;
        shape.draw(); // this'll give error cuz this is abstract class
    */
    return 0;
}