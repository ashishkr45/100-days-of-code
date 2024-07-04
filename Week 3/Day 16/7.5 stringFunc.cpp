#include <iostream>
#include <string>
using namespace std;

int main()
{

    string str = "Lucifero";

    /*for of loop*/
    for (char ch : str)
    {
        cout << ch << " ";
    }
    cout << endl;

    /*triditional iteration*/
    for (int i = 0; i < (int)str.length(); i++)
    {
        cout << str[i] << ", ";
    }
    cout << endl;

    /*CHecking String member functions*/

    // if that element is present
    cout << str.at(5) << endl;

    // if that element is not present
    cout << str.at(3) << endl;

    // making substrings,
    cout << str.substr(0, 7) << endl;

    // finding words
    string st = "when is next season of Black Colver coming";
    cout << st.find("Black") << endl;
    cout << st.find("season") << endl;

    return 0;
}