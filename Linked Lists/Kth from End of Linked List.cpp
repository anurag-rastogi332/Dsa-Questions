#include <iostream>
using namespace std;

/*

Input: LinkedList: 1->2->3->4->5->6->7->8->9, k = 2
Output: 8
Explanation: The given linked list is 1->2->3->4->5->6->7->8->9. The 2nd node from end is 8.

Input: LinkedList: 10->5->100->5, k = 5
Output: -1
Explanation: The given linked list is 10->5->100->5. Since 'k' is more than the number of nodes, the output is -1.


*/

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    int length(Node *head)
    {
        Node *temp = head;
        int l = 0;
        while (temp != NULL)
        {
            l++;
            temp = temp->next;
        }
        return l;
    }

    int getKthFromLast(Node *head, int k)
    {
        if (head == NULL)
        {
            return -1;
        }
        int l = length(head);
        if (k <= l)
        {
            Node *tmp = head;
            for (int i = 1; i < (l - k) + 1; i++)
            {
                tmp = tmp->next;
            }
            return tmp->data;
        }

        return -1;
    }
};

// Kth Node from End - Length Method (2 Traversal Approach)
//
// Idea:
// Convert "kth from end" into "position from start" using list length.
//
// Steps:
// 1. Traverse the list once to find total length 'l'.
// 2. If k > l, return -1 (kth from end does not exist).
// 3. Kth from end = (l - k + 1)th node from start.
// 4. Traverse from head to (l - k + 1)th position.
// 5. Return that node's data.
//
// Example:
// List: 1 -> 2 -> 3 -> 4 -> 5, k = 2
// Length l = 5
// Position from start = 5 - 2 + 1 = 4
// Answer = 4
//
// Time Complexity: O(n)  (two traversals)
// Space Complexity: O(1)
//
// Note:
// This method is simple and easy to implement,
// but does NOT satisfy "single traversal" constraint.
// For one-pass solution, use Fast & Slow pointer technique.

// method 2nd->

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int printKthFromEnd(ListNode *head, int k)
{
    if (head == NULL || k <= 0)
        return -1; // invalid case

    ListNode *fast = head;
    ListNode *slow = head;

    // Move fast pointer k steps ahead
    for (int i = 0; i < k; i++)
    {
        if (fast == NULL)
            return -1; // k is greater than length of list
        fast = fast->next;
    }

    // Move both pointers until fast reaches NULL
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // Now slow is at kth node from end
    return slow->val;
}

// Kth Node from End - Fast & Slow Pointer (Single Traversal)
//
// Idea:
// Use two pointers (fast and slow) to find kth node from end in one pass.
//
// Steps:
// 1. Initialize fast and slow at head.
// 2. Move fast pointer k steps ahead.
//    - If fast becomes NULL before k steps, k is invalid.
// 3. Move both fast and slow one step at a time.
// 4. When fast reaches NULL, slow is at the kth node from the end.
// 5. Return slow->val.
//
// Example:
// List: 1 -> 2 -> 3 -> 4 -> 5, k = 2
// After moving fast 2 steps: fast at 3
// Move both until fast == NULL:
//   fast: 4 -> 5 -> NULL
//   slow: 2 -> 3 -> 4
// Answer = 4
//
// Time Complexity: O(n)  (single traversal)
// Space Complexity: O(1)
//
// Why this is better:
// This approach satisfies the "single traversal" requirement
// and is optimal for interviews and large linked lists.


// Time Complexity Comparison (Kth Node from End)
//
// 1) Length Method (Two Traversals):
//    - First traversal: to find length  -> O(n)
//    - Second traversal: to reach (l-k+1)th node -> O(n)
//    - Total Time Complexity: O(n) + O(n) = O(n)  (but 2 passes)
//
// 2) Fast–Slow Pointer Method (Single Traversal):
//    - Move fast k steps -> O(k)
//    - Move fast & slow together till end -> O(n)
//    - Total Time Complexity: O(n)  (single pass)
//
// Space Complexity (Both):
//    - O(1)  (constant extra space)
//
// Interview Tip:
// Both are O(n), but Fast–Slow is preferred because
// it solves the problem in a single traversal.
