#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    int size(ListNode *head)
    {
        int count = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    bool isPalindrome(ListNode *head)
    {
        int count = 0;
        stack<int> check;
        ListNode *temp = head;
        while (count != size(head) / 2)
        {
            check.push(temp->val);
            temp = temp->next;
            count++;
        }

        while (temp->next != NULL)
        {
            if (temp->val == check.top())
            {
                check.pop();
                if (check.empty())
                {
                    return true;
                }
            }
            else
            {
                return false;
            }
            temp = temp->next;
        }
    }
};

int main()
{
    // Creating a simple linked list: 1 -> 2 -> NULL
    ListNode *node4 = new ListNode(45); // 2

    ListNode *node4 = new ListNode(45);       // 2
    ListNode *node1 = new ListNode(1, node4); // 1

    Solution s;
    bool result = s.isPalindrome(node1);
    cout << (result ? "The list is a palindrome" : "The list is not a palindrome") << endl;

    delete node4;
    delete node1;

    return 0;
}