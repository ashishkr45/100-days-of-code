#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream myFile;
    myFile.open("first.txt", ios::in); // output
    if (myFile.is_open())
    {
        string str;
        while (getline(myFile, str))
        {
            cout << str << endl;
        }
        myFile.close();
    }
    return 0;
}
