#include <iostream>
using namespace std;

// leetcode -> https://leetcode.com/problems/sort-list/description/

/*
Example:
Suppose the linked list is initially represented as:


head -> 4 -> 2 -> 1 -> 3
After sorting, the linked list should be rearranged to:


head -> 1 -> 2 -> 3 -> 4
Objective:
Write a function that accepts the head of the linked list, performs sorting, and returns the head of the sorted linked list.

Key Considerations:

You should focus on in-place sorting, maintaining the original nodes of the linked list wherever possible.
Avoid using additional data structures such as arrays for extracting and sorting the node values.
Example 1:

Input:

list = [4, 2, 1, 3]

Output:

[1, 2, 3, 4]
Explanation:Unsorted list is sorted to ascending order.

Example 2:

Input:

list = [-1, 5, 3, 4, 0]

Output:

[-1, 0, 3, 4, 5]
Explanation:Unsorted list with negative numbers is sorted.

Example 3:

Input:

list = []

Output:

[]
Explanation:Empty list remains empty after sorting.

*/


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

class Solution
{
public:
    ListNode *findMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val <= list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        if (list1 != NULL)
        {
            temp->next = list1;
        }
        else
        {
            temp->next = list2;
        }

        return dummy->next;
    }

    ListNode *sortList(ListNode *head)
    {

        if (head == 0 || head->next == 0)
        {
            return head;
        }

        // break LL into two halves using mid node
        ListNode *mid = findMid(head);

        ListNode *left = head;
        ListNode *right = mid->next;

        mid->next = 0;

        // recursive sort
        left = sortList(left);
        right = sortList(right);

        // merge both left and right LLs
        ListNode *mergedLL = mergeTwoLists(left, right);

        return mergedLL;
    }
};