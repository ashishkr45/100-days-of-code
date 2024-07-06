#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> vec = {1, 2, 3, 69};
    cout << "Size: " << vec.size() << endl;
    cout << "Size: " << vec.capacity() << endl; /*Yes, there's function for the capacity also*/

    vec.push_back(88); /*used to add elements al the end*/

    // now printing size and capacity to see changes
    cout << "Size: " << vec.size() << endl;
    cout << "Size: " << vec.capacity() << endl;

    /*and yes, there's a memer function to delete the last element*/
    vec.pop_back();

    // now again printing size and capacity to see changes
    cout << "Size: " << vec.size() << endl;
    cout << "Size: " << vec.capacity() << endl;

    return 0;
}