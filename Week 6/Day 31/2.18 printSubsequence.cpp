/*
Subsequence: A subsequence of a string is a sequence that can be derived from the original string by deleting some (or no) characters without changing the order of the remaining characters.

Let's consider the string "abc".
Subsequences:
    By taking no characters: "---" (the empty subsequence)
    By taking one character: "a--", "-b-", "--c"
    By taking two characters: "ab-", "a-c", "-bc"
    By taking all three characters: "abc"
    [- or empty space]
*/

#include <iostream>
#include <string>

using namespace std;

void Subsequence(string str, int idx, string ans)
{
    if (idx == (int)str.length())
    {
        cout << "Subsequence: \"" << ans << "\"" << endl;
        return;
    }

    // including the current char
    Subsequence(str, idx + 1, ans + str[idx]);

    // not including the current char
    Subsequence(str, idx + 1, ans);
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    Subsequence(str, 0, "");

    return 0;
}

/*
Recursion Tree for "abc":
    Subsequence("abc", 0, "")
        |
        |-- Subsequence("abc", 1, "a")
        |   |
        |   |-- Subsequence("abc", 2, "ab")
        |   |   |
        |   |   |-- Subsequence("abc", 3, "abc")   # Base case: prints "abc"
        |   |   |
        |   |   |-- Subsequence("abc", 3, "ab")    # Base case: prints "ab"
        |   |
        |   |-- Subsequence("abc", 2, "a")
        |       |
        |       |-- Subsequence("abc", 3, "ac")    # Base case: prints "ac"
        |       |
        |       |-- Subsequence("abc", 3, "a")     # Base case: prints "a"
        |
        |-- Subsequence("abc", 1, "")
            |
            |-- Subsequence("abc", 2, "b")
            |   |
            |   |-- Subsequence("abc", 3, "bc")    # Base case: prints "bc"
            |   |
            |   |-- Subsequence("abc", 3, "b")     # Base case: prints "b"
            |
            |-- Subsequence("abc", 2, "")
                |
                |-- Subsequence("abc", 3, "c")     # Base case: prints "c"
                |
                |-- Subsequence("abc", 3, "")      # Base case: prints ""
*/
