#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    float arr[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    for (int i = 0; i < (int)sizeof(arr) / sizeof(int); i++)
    {
        cout << fixed << setprecision(1) << arr[i] << " ";
    }
    cout << endl;

    string str;

    getline(cin, str);

    cout << str;

    return 0;
}