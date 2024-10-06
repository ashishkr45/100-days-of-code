#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream myFile; // creating a veriable of fstream type, which we use to manupulate files.
    /*here we'll be writing on the file, "first.txt" so out*/
    myFile.open("first.txt", ios::out); // write

    if (myFile.is_open()) // making sure the file is open
    {
        myFile << "Inputing for the first time.\n";
        /*feeding the value in a file is simlear to the way we output stuff to console*/
        myFile << "HMM, this shit's intersting\n";
        myFile.close();
        /*it's storing the files in the output folder*/
    }

    /*now if we want to keep the abive two lines and add more we'll open the file in append mode*/
    myFile.open("first.txt", ios::app); // append

    if (myFile.is_open())
    {
        myFile << "damm.\n";
        myFile.close();
    }
}