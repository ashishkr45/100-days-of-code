#include <iostream>
using namespace std;

int notes(int funds)
{
    int coins = 0;
    if (funds >= 2000)
    {
        funds = funds - 2000;
        coins++;
        cout << 2000 << " ";
        coins += notes(funds);
    }
    else if (funds >= 500)
    {
        funds = funds - 500;
        coins++;
        cout << 500 << " ";
        coins += notes(funds);
    }
    else if (funds >= 100)
    {
        funds = funds - 100;
        coins++;
        cout << 100 << " ";
        coins += notes(funds);
    }
    else if (funds >= 50)
    {
        funds = funds - 50;
        coins++;
        cout << 50 << " ";
        coins += notes(funds);
    }
    else if (funds >= 20)
    {
        funds = funds - 20;
        coins++;
        cout << 20 << " ";
        coins += notes(funds);
    }
    else if (funds >= 10)
    {
        funds = funds - 10;
        coins++;
        cout << 10 << " ";
        coins += notes(funds);
    }
    else if (funds >= 5)
    {
        funds = funds - 5;
        coins++;
        cout << 5 << " ";
        coins += notes(funds);
    }
    else if (funds >= 2)
    {
        funds = funds - 2;
        coins++;
        cout << 2 << " ";
        coins += notes(funds);
    }
    else if (funds >= 1)
    {
        funds = funds - 1;
        coins++;
        cout << 1 << " ";
        coins += notes(funds);
    }
    return coins;
}

int main()
{
    cout << "Enter the funds: ";
    int funds;
    cin >> funds;

    cout << "\nTotal coins/notes: " << notes(funds) << endl;
    return 0;
}
