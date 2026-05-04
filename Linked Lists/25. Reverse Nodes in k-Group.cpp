#include <iostream>
#include <algorithm>
using namespace std;

/*  Leetcode->25

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.



Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]


Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000


*/

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // step 1: check geoup of len k
        int count = 0;
        ListNode *temp = head;
        while (temp != NULL && count < k)
        {
            temp = temp->next;
            count++;
        }
        // if goup exist
        if (count == k)
        {
            // reverse 1 group and baaki recusion dekh lega
            ListNode *prev = NULL;
            ListNode *curr = head;
            ListNode *forward = NULL;

            int i = 0;
            while (i < k)
            {
                forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
                i++;
            }
            // hmne 1 group ko reverse kr diya hai
            // baki ke recusion solve kr dega
            ListNode *recusionHead = reverseKGroup(forward, k);
            // dono ko join krdo
            head->next = recusionHead;
            // return starting node of the linkedlist
            return prev;
        }
        else
        {
            return head;
        }
    }
};