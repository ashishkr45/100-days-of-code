#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> vec1;
    cout << "the size of empty vector: " << vec1.size() << endl;

    // another way to declear
    vector<int> vec2 = {1, 2, 3, 4, 5};
    // cout << vec2 << endl;

    // initilizing with fill constructor
    vector<int> vec3(5, -1);
    /*here a vector of size 5 is created and intilized with -1*/
    // cout << vec3 << endl;

    return 0;
}