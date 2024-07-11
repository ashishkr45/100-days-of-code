#include <iostream>
using namespace std;

void countbBits(int num);

int main()
{

    int num;
    cout << "Enter a number: ";
    cin >> num;

    countbBits(num);

    return 0;
}

void countbBits(int num)
{
    int count = 0;
    while (num > 0)
    {
        int last = num & 1;
        count += last;
        num = num >> 1;
    }
    cout << "Count: " << count << endl;
    return;
}
