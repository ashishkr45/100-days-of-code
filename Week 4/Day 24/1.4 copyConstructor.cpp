#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
    string model;
    string colour;
    int *enginNo;

    Car(string model, string colour, int enginNo)
    {
        this->model = model;
        this->colour = colour;
        this->enginNo = new int(enginNo); // dynamic allocation and initialization
    }

    /*custom copy constructor*/
    Car(Car &car)
    {
        cout << "using custom copy constructor here" << endl;
        model = car.model;
        colour = car.colour;
        // enginNo = car.enginNo; this will create a shallow copy
        enginNo = new int(*(car.enginNo)); // deep copy
    }

    ~Car()
    {
        cout << "Deleating objects" << endl;
        if (enginNo != NULL)
        {
            delete enginNo;
            /*here first it'll delete the memory which this
             varibale is pointing then store garbage address(value) in it.*/
            enginNo = NULL;
            /*null != garbage value(this have a address assined to it)
            wherease null = there's no valid address stored here.*/
        }
    }
};

int main()
{
    string car, colour;
    int engNO;

    // cout << "Enter the name of car: ";
    // cin >> car;
    // cout << "Colour of the car: ";
    // cin >> colour;

    Car car1("Porsche", "matt black", 12);
    Car car2(car1); // we're using copy constructor here
    cout << car2.model << endl;
    cout << car2.colour << endl;
    cout << *car2.enginNo << endl;

    /*changing car2 enginNo*/
    cout << "enter Engin no: ";
    cin >> engNO; // this'll not work cuz we initilized deep copy
    *car2.enginNo = engNO;

    cout << *car1.enginNo << endl;
    return 0;
}