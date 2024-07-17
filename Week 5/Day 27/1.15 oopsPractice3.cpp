#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    string name;
    int age;
};

class Student : public Person
{
public:
    string studentId;

    Student(string name, int age, string id)
    {
        this->name = name;
        this->age = age;
        this->studentId = id;
    }

    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Student Id: " << studentId << endl;
        return;
    }
};

int main()
{
    Student std1("Luci", 19, "12319558x");
    std1.displayInfo();
}