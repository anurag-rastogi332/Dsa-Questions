#include <iostream>
using namespace std;

/*

Given the head of a linked list, remove the nth node from the end of the list and return its head.



Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]




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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL || n <= 0)
            return head;

        // Find length
        int l = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            l++;
            temp = temp->next;
        }

        // check karo valid node to delete
        if (n > l)
            return head;

        // agar first node hai then
        if (n == l)
        {
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }

        //  Go to (l - n)th node
        ListNode *prev = head;
        for (int i = 1; i < (l - n); i++)
        {
            prev = prev->next;
        }

        // Delete the (l - n + 1)th node
        ListNode *del = prev->next;
        prev->next = del->next;
        delete del;

        return head;
    }
};