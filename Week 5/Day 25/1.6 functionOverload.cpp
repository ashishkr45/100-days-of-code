#include <iostream>
#include <string>
using namespace std;

class Overload
{
public:
    void print(int n)
    {
        if (n <= 1)
        {
            cout << 1 << " ";
            return;
        }
        print(n - 1); // Recursive call
        cout << n << " ";
    }


    void print(string input)
    {
        for (int i = 0; i < (int)input.length(); i++)
        {
            cout << input[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Overload over;
    over.print(15);
    cout << endl;
    over.print("Input");
    return 0;
}