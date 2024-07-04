/*Leetcode Problem 242*/

/*
in this question we're gonna take two inputs
    1. the original word
    2. the anagram(An anagram is a word formed by rearranging the letters of a different word)

Solution approach:
    we are gonna make an array for the number of times of the occurance of a char in the OriginalWord
    and gonna stroe it in the index of the count array.

    ex: abba
    count:: 0 0 0 0 0 0 (initially it's gonna be zero)
            0 1 2 3 4 5 (index acc to the )
            a b c d e f (alphabets)

    count:: 1 2 0 0 0 0 (after the process)

    this'll give us the exactly which word is present for how many times and we'll compare it with
    the anagram word if matches it an anagram and we'll return true.
*/

#include <iostream>
#include <string>
using namespace std;

void anaCheck(string str, string strAna);

int main()
{
    string str, anaStr;

    cout << "Enter the original string: ";
    cin >> str;

    cout << "Enter the Anagram string: ";
    cin >> anaStr;

    anaCheck(str, anaStr);

    return 0;
}

void anaCheck(string str, string strAna)
{
    if (str.length() != strAna.length())
    {
        cout << "Not an Anagram";
        return;
    }

    int count[26] = {0}; // Initialize the array to zero

    // Count characters in the original string
    for (int i = 0; i < (int)str.length(); i++)
    {
        count[str[i] - 'a']++;
    }

    // Subtract counts based on the anagram string
    for (int i = 0; i < (int)strAna.length(); i++)
    {
        count[strAna[i] - 'a']--;
    }

    // Check if all counts are zero
    for (int i = 0; i < 26; i++)
    {
        if (count[i] != 0)
        {
            cout << "Not an Anagram";
            return;
        }
    }
    cout << "It's an Anagram";
    return;
}
