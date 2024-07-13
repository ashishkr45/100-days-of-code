#include <iostream>
#include <string>
using namespace std;

class Car
{
    string model;
    string colour;

public:
    Car()
    {
        cout << "This is non-parameterized constructor" << endl;
    }

    Car(string modelVal, string colourVal)
    {
        cout << "This is parameterized constructor" << endl;
        // model = modelVal; or
        this->model = model;
        // colour = colourVal;
        this->colour = colour;
        // or, *this.colour = colour;
    }

    void start()
    {
        cout << "Car's now running" << endl;
    }
    void stop()
    {
        cout << "not running now" << endl;
    }

    void setModel(string modelVal)
    {
        model = modelVal;
    }

    void setColour(string colourVal)
    {
        colour = colourVal;
    }

    /*getters: we use them to get those valuse.*/
    string getModel()
    {
        return model;
    }

    string getColour()
    {
        return colour;
    }
};

int main()
{
    Car c0;                         // non-parameterized constructor
    Car c1("Maruti Omni", "white"); // parameterized constructor
    Car c2("porsche", "matt black");

    // cout << "Car name: " << c1.getModel() << endl;
    // cout << "Car colour: " << c1.getColour() << endl;

    return 0;
}
