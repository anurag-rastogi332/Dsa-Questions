#include <iostream>
using namespace std;

/*

Example 1:

Input: head = [1,2,3,4,5]

Output: [5,4,3,2,1]

Example 2:

Input: head = [1,2]

Output: [2,1]

Input Format The input is the head of the linked list.

Output Format Return the head of the reversed linked list.

Example 1:

Input:

head = [1,2,3,4,5]

Output:

5 4 3 2 1
Explanation:The list [1,2,3,4,5] is reversed.

Example 2:

Input: head = [1,2]

Output: '2 1 '

Example 3:

Input: head = []

Output: ''

*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }

        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr != NULL)
        {
            ListNode *Forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Forward;
        }
        // update head
        head = prev;
    }
};

// 🔁 Reverse Linked List - Short Notes (VS Code Comments)
//
// Goal:
// Reverse the direction of a singly linked list.
// Example: 1 -> 2 -> 3 -> NULL  becomes  3 -> 2 -> 1 -> NULL
//
// Key Idea (3 Pointer Technique):
// prev  -> previous node (initially NULL)
// curr  -> current node (initially head)
// forward -> next node (used to store curr->next before breaking the link)
//
// Steps inside loop:
// 1. forward = curr->next;     // save next node
// 2. curr->next = prev;        // reverse the link
// 3. prev = curr;              // move prev forward
// 4. curr = forward;           // move curr forward
//
// Base Case:
// If head == NULL, return NULL (empty list)
//
// After loop:
// prev becomes the new head of the reversed list.
//
// Time Complexity: O(n)  -> traverse each node once
// Space Complexity: O(1) -> no extra memory used
//
// Common Mistakes:
// - Forgetting: curr->next = prev;   // link won't reverse
// - Not saving next node (forward)   // list can break
// - Forgetting to return new head

