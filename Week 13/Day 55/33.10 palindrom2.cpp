#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

class Solution
{
public:
    bool isPalindrome(Node *head)
    {
        Node *temp = head;
        stack<int> check;

        // Push all values onto the stack
        while (temp != nullptr)
        {
            check.push(temp->val);
            temp = temp->next;
        }

        // Compare the stack with the original linked list
        Node *temp_two = head;
        while (temp_two != nullptr)
        {
            if (temp_two->val != check.top())
            {
                return false; // If any value doesn't match, it's not a palindrome
            }
            check.pop();
            temp_two = temp_two->next;
        }

        return true; // All values matched, so it's a palindrome
    }
};

int main()
{
    // Creating a simple linked list: 1 -> 2 -> 2 -> 1 -> NULL
    Node *node4 = new Node(1);        // Node 4
    Node *node1 = new Node(1, node4); // Node 1

    Solution s;
    bool result = s.isPalindrome(node1);
    cout << (result ? "The list is a palindrome" : "The list is not a palindrome") << endl;

    // Clean up memory
    delete node4;
    delete node1;

    return 0;
}
