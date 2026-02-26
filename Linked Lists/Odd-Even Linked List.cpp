#include <iostream>
using namespace std;
/*

Example
Input:

A linked list: 1 -> 2 -> 3 -> 4 -> 5

Output:

A reordered linked list: 1 -> 3 -> 5 -> 2 -> 4

Explanation:

In this example, all the nodes which are located at odd indices (1, 3, 5) are rearranged before the nodes at even indices (2, 4). The initial relative order of odd and even indexed nodes is maintained in the final rearranged list.

Example 1:

Input:

head = [1, 2, 3, 4, 5]

Output:

[1, 3, 5, 2, 4]
Explanation:Nodes at odd indices (1, 3, 5) are grouped, followed by even indices (2, 4).

Example 2:

Input:

head = [2, 1, 3, 5, 6, 4, 7]

Output:

[2, 3, 6, 7, 1, 5, 4]
Explanation:Nodes at odd indices are grouped, followed by even indices in their original order.

Example 3:

Input:

head = [1, 2]

Output:

[1, 2]
Explanation:Only two nodes; no reordering required.

*/

// Definition for singly-linked list.
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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || head->next == 0)
            return head;
        // h1->odd node list bnayega
        // h2 even index list bnayega
        ListNode *h1 = head, *h2 = head->next;
        // store the even head
        ListNode *evenHead = h2;
        while (h2 && h2->next)
        {
            h1->next = h2->next;
            h2->next = h2->next->next;
            h1 = h1->next;
            h2 = h2->next;
        }
        // two independent prepared list has been regrouped
        //  odd index wali list ->even index wali list
        h1->next = evenHead;
        return head;
    }
};



/*
Problem:
Rearrange the linked list so that all nodes at odd positions come first,
followed by nodes at even positions. Relative order must be preserved.

Approach:
- Maintain two pointers:
  - h1 for odd-indexed nodes
  - h2 for even-indexed nodes
- Traverse the list and rewire pointers to form two separate chains:
  odd list and even list
- After traversal, attach the even list after the odd list
- Perform all operations in-place without creating new nodes

Algorithm:
1. If list is empty or has only one node, return head
2. Initialize h1 = head, h2 = head->next
3. Store evenHead = h2 for final connection
4. While h2 and h2->next exist:
   - h1->next = h2->next
   - h2->next = h2->next->next
   - Move h1 and h2 forward
5. Connect odd list tail to evenHead
6. Return head

Time Complexity: O(n)
Space Complexity: O(1)
*/