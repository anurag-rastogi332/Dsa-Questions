#include <iostream>
using namespace std;

/*

Example 1:
Input: head = [1,4,3,2,5,2], x = 3

Output: [1,2,2,4,3,5]

Explanation:
Nodes 1, 2, and 2 are less than 3 and appear first, in their original order. Nodes 4, 3, and 5 are greater than or equal to 3 and appear next, also in their original order.

Example 2:
Input: head = [2,1], x = 2

Output: [1,2]

Explanation:
Node 1 is less than 2. Node 2 is greater than or equal to 2.

Input Format
The input will be the head of the linked list and an integer x.

Output Format
Return the head of the modified, partitioned linked list.

Example 1:

Input: n=3 x=6 head=[-9,9,-10]

Output: '-9 -10 9 '

Example 2:

Input: n=1 x=5 head=[6]

Output: '6 '

Example 3:

Input: n=10 x=7 head=[-4,8,-10,-7,5,2,0,-3,-1,4]

Output: '-4 -10 -7 5 2 0 -3 -1 4 8 '

*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *fp = new ListNode(-1);
        ListNode *sp = new ListNode(-1);
        // dummy head ke liye pointers
        auto fpTail = fp;
        auto spTail = sp;
        // original ll ko traverse krne ke liye pointer
        auto it = head;
        while (it)
        {

            if (it->val < x)
            {
                // first part
                fpTail->next = it;
                fpTail = fpTail->next;
            }
            else
            {
                spTail->next = it;
                spTail = spTail->next;
            }
            it = it->next;
        }
        // fp->next || sp->NULL
        fpTail->next = sp->next;
        spTail->next = 0;

        return fp->next;
    }
};

/*
Problem:
Partition a linked list around value x such that:
- All nodes with value < x come before nodes with value >= x
- Relative order of nodes in each partition is preserved

Approach:
- Create two dummy heads:
  - First list for nodes < x
  - Second list for nodes >= x
- Traverse the original list once and attach nodes to the respective lists
- Connect the end of the first list to the start of the second list
- Terminate the second list to avoid cycles

Algorithm:
1. Initialize two dummy nodes (fp, sp) and their tails (fpTail, spTail)
2. Traverse the list using pointer it
3. If it->val < x, attach to first list
   Else attach to second list
4. Connect fpTail->next to sp->next
5. Set spTail->next = NULL
6. Return fp->next as new head

Time Complexity: O(n)
Space Complexity: O(1)
*/