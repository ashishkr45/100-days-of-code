/*
Checking bitwise Operators
bitwise AND (&)
bitwise OR (|)
bitwise XOR (^)
*/

#include <iostream>
using namespace std;

int main()
{

    int a, b;
    cout << "Enter number a: ";
    cin >> a;

    cout << "Enter number b: ";
    cin >> b;

    int op = a & b;
    int op1 = a | b;
    int op2 = a ^ b;
    int op3 = ~a;

    cout << "Result of Birwise AND: " << op << endl;
    cout << "Result of Birwise OR: " << op1 << endl;
    cout << "Result of Birwise XOR: " << op2 << endl;
    cout << "Result of Birwise NOT: " << op3 << endl;
    toBinary(op3);

    return 0;
}
