//! this question is is still not solved

/*
! the error: Line 14: Char 16: runtime error: 9.64632e+09 is outside the range of representable values of type 'int' (solution.cpp)
! SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior solution.cpp:14:16

* it's failing at this, x = 1534236469 input.

*/
#include <iostream>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        bool neg = x < 0;
        /*
        todo: we're setting the -ve numbers and -(-num) which'll make it +ve easy to work
        */
        if (neg)
        {
            x = -x;
        }
        double num = 0;
        while (x > 0)
        {
            int last = x % 10;
            num = num * 10 + last;
            x /= 10;
        }
        return neg ? -num : num;
    }
};

int main()
{
    Solution s;
    cout << s.reverse(-2147483648);

    return 0;
}