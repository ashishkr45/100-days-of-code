#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;
    for (int i = 0; i < 5; i++)
    {
        cin >> vec[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cout << vec[i];
    }
}