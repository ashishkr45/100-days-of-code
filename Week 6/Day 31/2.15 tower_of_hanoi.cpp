/*
RULES
1. Only one disk transferred in 1 step
2. Smaller disks are slways kept on top of larger disks

STEPS
1. transfer (n-1) disks to the [helper]
2. transer the larges disk to the [destination] fron [source] (we can do it directly)
3. transfering the (n-1) disks to the [destination] using [souce] as [helpher]

Time complexity fir this will be : O(2^n)
*/

#include <iostream>
#include <string>

using namespace std;

void tower_of_hanoi(int n, string src, string helper, string dest)
{
    if (n == 1)
    {
        cout << "transfer disk " << n << " form " << src << " to " << dest << endl;
        return;
    }

    // step_1 : transfering n-1 disks from the source to the helper using dest as helper
    tower_of_hanoi(n - 1, src, dest, helper);
    cout << "transfer disk " << n << " form " << src << " to " << dest << endl;

    // step_3 : transfering the n-1 disks from helpher to dest using source as helper
    tower_of_hanoi(n - 1, helper, src, dest);
}

int main()
{
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    tower_of_hanoi(n, "src", "helper", "dest");

    return 0;
}
