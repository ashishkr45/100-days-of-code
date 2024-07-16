#include <iostream>
#include <string>
using namespace std;

class Complex
{
    int real, imag;

public:
    Complex(int r, int i)
    {
        real = r;
        imag = i;
    }

    void showNo()
    {
        cout << real << " + " << imag << "i" << endl;
    }

    /*Oerator Overloading*/
    void operator+(Complex &c2)
    {
        int realRes = this->real + c2.real;
        int imgRes = this->imag + c2.imag;
        Complex c3(realRes, imgRes);
        cout << "Result: ";
        c3.showNo();
    }
};

int main()
{
    Complex c1(1, 3);
    Complex c2(2, 6);
    cout << "First no: ";
    c1.showNo();
    cout << endl;
    cout << "Second no: ";
    c2.showNo();
    cout << endl;

    c1 + c2;

    return 0;
}