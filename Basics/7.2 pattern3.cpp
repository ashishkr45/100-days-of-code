#include <iostream>
using namespace std;
/*
 * * * * *
 * * * *
 * * *
 * *
 *
 */
int main()
{

    // method 1
    //  for (int i = 1; i <= 5; i++)
    //  {
    //      for (int j = 1; j <= 6 - i; j++)
    //      {
    //          cout << "*";
    //      }
    //      cout << endl;
    //  }

    // method 2
    for (int i = 5; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}