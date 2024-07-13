#include <iostream>
#include <string>
using namespace std;

class Student // first letter should be upperCase
{
    /*properties*/
    string name;
    float cgpa;

public:
    Student() // this is usually used for initilisation of variables
    {
        cout << "This is constructor" << endl;
    }
    /*Methods*/
    void percentage()
    {
        cout << (cgpa * 10) << "%" << endl;
    }
    /*Setter: we use them when we don't want to give complete access to a property*/
    void setName(string nameVal)
    {
        name = nameVal;
    }

    void setCgpa(float cgpaVal)
    {
        cgpa = cgpaVal;
    }

    /*getters: we use them to get those valuse.*/
    string getName()
    {
        return name;
    }

    float getCgpa()
    {
        return cgpa;
    }
};

int main()
{
    /*
    Student s1; // object
    s1.name = "Ashish Kumar";
    s1.cgpa = 7.11;

    cout << s1.name << endl;
    s1.percentage();
    */

    Student s1;
    s1.setName("Luci");
    s1.setCgpa(7.11);

    cout << s1.getName() << endl;
    cout << s1.getCgpa() << endl;

    return 0;
}