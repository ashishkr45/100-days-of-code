#include <iostream>
#include <climits>
using namespace std;

bool isPalindrome(int x) {
	if(x < 0) return false;
        int og = x;
        int rev = 0;
        while (x != 0) {
            int last = x % 10;

            if (rev > INT_MAX / 10) return 0;
            if (rev < INT_MIN / 10) return 0;

            rev = (rev * 10) + last;
            x /= 10;
        }
        return rev == og;
}

int main() {
    int n;
    cin >> n;
    // int original_n = n; // Store the original value of n for later use

    // Print each digit of n
    // while (n > 0) {
    //     int last = n % 10;
    //     cout << last << " ";
    //     n /= 10;
    // }
    // cout << endl;

    cout<<isPalindrome(n); // Pass the original value to evenlyDivides
}
