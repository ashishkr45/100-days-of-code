#include <iostream>
using namespace std;

int main()
{

    int num, temp;
    int revNum = 0;

    cout << "Enter a number: ";
    cin >> num;

    while (num != 0)
    {
        temp = num % 10;
        revNum = revNum * 10 + temp;
        num = num / 10;
    }

    cout << "Reverced number: " << revNum;

    return 0;
}