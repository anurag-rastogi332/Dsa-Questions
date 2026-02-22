#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// this is a recusion solution of problem

/*

You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

Return the head of the linked list after doubling it.



Example 1:


Input: head = [1,8,9]
Output: [3,7,8]
Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.
Example 2:


Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998.

*/

class Solution
{
public:
    // tail se start karke recursion ke through digits process karta hai
    void solve(ListNode *head, int &carry)
    {
        // base case
        if (head == NULL)
        {
            return;
        }
        // pehle end tak jao
        solve(head->next, carry);
        // current digit ko double + carry
        int prod = head->val * 2 + carry;
        head->val = prod % 10;
        carry = prod / 10;
    }

    ListNode *doubleIt(ListNode *head)
    {
        int carry = 0;

        // recursion se poori list process karo
        solve(head, carry);
        if (carry)
        {
            // agar MSB pe carry bacha ho to new node add karo
            ListNode *carryNode = new ListNode(carry);
            carryNode->next = head;
            head = carryNode;
        }
        return head;
    }
};

// using iteration method ro solve this problem

class Solution
{
public:
    // sabse pehle hum linked list ko reverse karenge
    ListNode *reverseLL(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        while (curr != NULL)
        {
            ListNode *forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode *doubleIt(ListNode *head)
    {
        if (head == NULL)
            return NULL;

        // pehle linked list ko reverse kar rahe hain
        head = reverseLL(head);

        ListNode *temp = head;
        int carry = 0;

        // yaha hum har digit ko 2 se multiply karenge
        // aur carry ko next node tak propagate karenge
        while (temp != NULL)
        {
            int sum = temp->val * 2 + carry;
            temp->val = sum % 10;
            carry = sum / 10;

            // agar last node pe carry bacha ho
            // to ek naya node add kar denge
            if (temp->next == NULL && carry > 0)
            {
                temp->next = new ListNode(carry);
                carry = 0;
                break;
            }

            temp = temp->next;
        }

        // finally, list ko dobara reverse kar denge
        head = reverseLL(head);
        return head;
    }
};