#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of char: ";
    cin >> n;

    char arr[n + 1];
    cout << "Enter a string: ";
    cin >> arr;

    int size = n + 1;
    bool check = 1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] != arr[size - i])
        {
            check = 0;
            break;
        }
    }

    if (check == true)
    {
        cout << "Word is Palindrome" << endl;
    }
    else
    {
        cout << "Word is not Palindrome" << endl;
    }

    return 0;
}