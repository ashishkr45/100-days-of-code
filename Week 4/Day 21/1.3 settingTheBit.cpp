#include <iostream>
using namespace std;

void getTheBit(int num, int i);
void setTheBit(int num, int i);
void clearTheBit(int num, int i);

int main()
{

    int num, i;
    cout << "Enter the number: ";
    cin >> num;

    cout << "Enter the number(i): ";
    cin >> i;

    getTheBit(num, i);
    setTheBit(num, i);
    clearTheBit(num, i);

    return 0;
}

void getTheBit(int num, int i)
{
    int bitMask = 1 << i;

    if (!(num & bitMask))
    {
        cout << "0" << endl;
        return;
    }
    else
    {
        cout << "1" << endl;
        return;
    }
    return;
}

void setTheBit(int num, int i)
{
    int bitMask = 1 << i;

    cout << (num | bitMask) << endl;

    return;
}

void clearTheBit(int num, int i)
{
    int mask = ~(1 << i);
    cout << (num & mask) << endl;
}