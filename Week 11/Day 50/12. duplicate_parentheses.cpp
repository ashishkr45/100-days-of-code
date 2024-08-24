/*
Duplicate Parentheses

(x+y) No extra Parentheses - false
((x+y)+z) again no extra Parentheses - false
((x+y)) there's extra Parentheses - true
((x+y) + ((z))) extra Parentheses here: ((Z)) - true
*/

/*Apporach:
We'll boundle the expression and the opening and closing brackets and remove it(removing it is for understanding)
and if it is contaning "Duplicate Parentheses" it'll be with just empty space 'No valid expression'
example:
    ((x+y)) bundling the onening and closing parentheses with the expression and removing
        i.e. (x+y) the bundled part
            the left over (  ) with just empty space

    we'll travel through the entire expression and push everything in the stack it we get the closing Parentheses,
    ones we reach the closing Parentheses we'll pop everything till we get to the opening Parentheses and pop that too.
    we poped (x+y). things still in the stack will be ( .
    after that we'll reach the 'extra closing Parentheses' it'll find it's opening pair at top of the stack then we'll
    conclude it's a "Duplicate Parentheses"
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool Duplicacy(string str)
{
    stack<char> stk;

    for (int i = 0; i < (int)str.size(); i++)
    {
        if (str[i] != ')') // non-closing
        {
            stk.push(str[i]);
        }
        else // closing
        {
            if (stk.top() == '(')
            {
                return true; // Duplicacy_found
            }

            while (stk.top() != '(')
            {
                stk.pop();
            }
            stk.pop();
        }
    }
    return false;
}

int main()
{

    string str1 = "(((a+b)) + c)"; // Duplicacy: true
    string str2 = "(a+b)";         // no-duplicacy: false

    cout << Duplicacy(str1) << endl; // 1
    cout << Duplicacy(str2) << endl; // 0

    return 0;
}