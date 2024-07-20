/*
here we're gonna take a number input and print a string of 0's & 1's
where there string with no consucitive 1
example:
    1010    (accetable)
    1001    (accetable)
    1100    (not-accetable)
*/

#include <iostream>
#include <string>
using namespace std;

void binString(int n, int lastStr, string ans)
{
    if (n == 0)
    {
        cout << "Binary String: " << ans << endl;
        return;
    }
    if (lastStr != 1)
    /*here we'll not put the condition of lastStr == 0,
        cuz, initially when the ans is initilised it'll be a enpty string
        which'll not be equal to 0*/
    {
        binString(n - 1, 0, ans + '0');
        binString(n - 1, 1, ans + '1');
    }
    else
    {
        binString(n - 1, 0, ans + '0');
    }
}
/*without extra variable of last string*/
void bitString(int n, string ans)
{
    if (n == 0)
    {
        cout << "Binary String: " << ans << endl;
        return;
    }
    if (ans[ans.size() - 1] != '1')
    {
        bitString(n - 1, ans + '0');
        bitString(n - 1, ans + '1');
    }
    else
    {
        bitString(n - 1, ans + '0');
    }
}

int main()
{

    int num;
    cout << "Enter the length of string: ";
    cin >> num;

    string ans;

    bitString(num, ans);

    return 0;
}

/*
Here's a visulation for how the recursion tree will look like
bitString(3, "")
    ├── bitString(2, "0")
    │   ├── bitString(1, "00")
    │   │   ├── bitString(0, "000") -> "Binary String: 000"
    │   │   └── bitString(0, "001") -> "Binary String: 001"
    │   └── bitString(1, "01")
    │       ├── bitString(0, "010") -> "Binary String: 010"
    │       └── bitString(0, "011") -> "Binary String: 011"
    └── bitString(2, "1")
        ├── bitString(1, "10")
        │   ├── bitString(0, "100") -> "Binary String: 100"
        │   └── bitString(0, "101") -> "Binary String: 101"
        └── (Skipped, as it would start with "11")

*/