#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    void eat()
    {
        cout << "Food's over" << endl;
    }
    void sleep()
    {
        cout << "It's sleeping" << endl;
    }
};

class Fish : public Animal
{
public:
    void swim()
    {
        cout << "Fish is dead" << endl;
    }
};

class Bird : public Animal
{
public:
    void Fly()
    {
        cout << "Bird is dead" << endl;
    }
};

class Malmal : public Animal
{
public:
    void walk()
    {
        cout << "Don't have legs" << endl;
    }
};

int main()
{
    Fish salmon;
    salmon.eat();
    salmon.sleep();
    salmon.swim();

    return 0;
}