#include <iostream>
using namespace std;

int main()
{
    int amt1, amt2;
    // displaying a message so that it's visible in the terminal
    cout << "Enter the first amount: ";
    // we use cin to take input from the user in terminal
    cin >> amt1;

    cout << "Enter the secound amount: ";
    cin >> amt2;

    // printing the sum of both the amt.
    cout << "Total amount: " << amt1 + amt2 << endl;
    // endl is used to insert a new line characters
    return 0;
}