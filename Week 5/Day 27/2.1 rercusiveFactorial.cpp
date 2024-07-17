/*Recursion: It is a method of solving computational problems where the solution depends on solutions to
smaller instances of the same problem.*/

#include <iostream>
using namespace std;

long long int Factorial(int n)
{
    if (n == 1) // this is the base case i.e. where solution is known.
    {
        return 1;
    }
    return n * Factorial(n - 1);
}

int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;

    if (num == 0)
    {
        cout << "Factorial of 0 is: 1" << endl;
    }

    cout << "Factorial of " << num << " is: " << Factorial(num) << endl;

    return 0;
}