#include <iostream>
using namespace std;

/*

Example:
Input:

Linked List: 1 -> 2 -> 3 -> 4 -> 5
k = 2
Output:

Rotated List: 4 -> 5 -> 1 -> 2 -> 3
Consider corner cases such as when the list is empty, has only one node, or when the value of k is larger than the length of the list. The task is to perform this rotation operation in an efficient manner and return the new head of the list.

Example 1:

Input: head = [1, 2, 3, 4, 5], k = 2

Output: [4, 5, 1, 2, 3]

Example 2:

Input: head = [], k = 1

Output: []

Example 3:

Input: head = [1], k = 99

Output: [1]

Constraints

• The number of nodes in the list is in the range [0, 500].
• -100 <= Node.val <= 100
• 0 <= k <= 2 * 10^9

*/

//  Definition for singly-linked list.
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
    int getLength(ListNode *head)
    {
        int len = 0;
        while (head)
        {
            ++len;
            head = head->next;
        }
        return len;
    }

    ListNode *rotateRight(ListNode *head, int k)
    {

        if (!head)
            return 0;

        int len = getLength(head);

        int actualRotatek = (k % len);

        if (actualRotatek == 0)
            return head;

        int newLastNodePos = len - actualRotatek - 1;

        ListNode *newLastNode = head;

        for (int i = 0; i < newLastNodePos; i++)
        {

            newLastNode = newLastNode->next;
        }

        ListNode *newHead = newLastNode->next;

        newLastNode->next = 0;
        ListNode *it = newHead;
        while (it->next)
        {
            it = it->next;
        }
        it->next = head;
        return newHead;
    }
};
