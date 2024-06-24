#include <bits/stdc++.h>
using namespace std;

int addBinary(int a, int b);
int reverse(int n);

int main()
{

    int a, b;
    cout << "Enter two binary numbers for Addition." << endl;
    cout << "1st number: ";
    cin >> a;

    cout << "1nd number: ";
    cin >> b;

    cout << "The sum is: " << addBinary(a, b) << endl;

    return 0;
}

int addBinary(int a, int b)
{
    int ans = 0;
    int carry = 0;

    while (a > 0 && b > 0)
    {
        if (a % 2 == 0 && b % 2 == 0)
        {
            ans = ans * 10 + carry;
            carry = 0;
        }
        else if ((a % 2 == 0 && b % 2 == 1) || (a % 2 == 1 && b % 2 == 0))
        {
            if (carry == 1)
            {
                ans = ans * 10 + 0;
                carry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                carry = 0;
            }
        }
        else
        {
            ans = ans * 10 + carry;
            carry = 1;
        }
    }

    while (a > 0) // if b is short then A and now a few numbers of a are left.
    {
        if (carry == 1)
        {
            if (a % 2 == 1)
            {
                ans = ans * 10 + 0;
                carry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                carry = 0;
            }
        }
        else
        {
            ans = ans * 10 + (a % 2);
        }
        a /= 10;
    }

    while (b > 0)
    {
        if (carry == 1)
        {
            if (b % 2 == 1)
            {
                ans = ans * 10 + 0;
                carry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                carry = 0;
            }
        }
        else
        {
            ans = ans * 10 + (b % 2);
        }
        b /= 10;
    }

    if (carry == 1) // if both numbers are exactely of the same length and now there is leftover carry.
    {
        ans = ans * 10 + 1;
    }

    // since the numbers are being added in reversed order,
    // like the first number added will be from the last so we need to reverse the number.

    ans = reverse(ans);
    return ans;
}

int reverse(int n)
{
    int ans = 0;
    while (n > 0)
    {
        int last = n % 10;
        ans = ans * 10 + last;
        n /= 10;
    }
    return ans;
}