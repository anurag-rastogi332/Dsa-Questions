#include <iostream>
using namespace std;
/*

Example 1:

Input: head = [1,2,3]

Output: [1,2,4]

Explanation: The list represents the number 123. 123 + 1 = 124.

Example 2:

Input: head = [4,5,9]

Output: [4,6,0]

Explanation: The list represents the number 459. 459 + 1 = 460.

Input Format The input is the head of the linked list.

Output Format Return the head of the resulting linked list.

Example 1:

Input: head = [1,2,3]

Output: '1 2 4'

Example 2:

Input: head = [4,5,9]

Output: '4 6 0'

Example 3:

Input: head = [9]

Output: '1 0'

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

    ListNode *plusOne(ListNode *head)
    {
        if (head == NULL)
        {
            return new ListNode(1);
        }

        head = reverseLL(head);

        ListNode *temp = head;
        int carry = 1;

        while (temp)
        {
            int sum = temp->val + carry;
            temp->val = sum % 10;
            carry = sum / 10;

            if (carry == 0)
                break;

            if (temp->next == NULL && carry)
            {
                temp->next = new ListNode(carry);
                carry = 0;
            }

            temp = temp->next;
        }

        head = reverseLL(head);
        return head;
    }
};

/*

🔹 Approach / Algorithm (Professional Logic Notes)

Reverse the Linked List

Since addition starts from the least significant digit, reverse the list to process from the tail.

Initialize Carry

Set carry = 1 to perform the “+1” operation.

Traverse and Update Digits

For each node:

sum = node->val + carry

Update digit: node->val = sum % 10

Update carry: carry = sum / 10

If carry becomes 0, terminate traversal early (no further propagation needed).

Handle Remaining Carry

If carry is still 1 after the last node, create a new node with value carry and attach it at the end.

Reverse the Linked List Back

Restore the original digit order by reversing the list again.

🔹 Edge Case Handling

Empty Linked List (head == NULL)

Return a new node with value 1.

All Digits are 9

Example: 9 → 9 → 9

Result: 1 → 0 → 0 → 0 (new most significant digit added)

No Carry Propagation Case

Example: 1 → 2 → 3

Only the last digit is updated.

🔹 Complexity Analysis

Time Complexity: O(n)
(Reversal + traversal + reversal)

Space Complexity: O(1)
(In-place modification; no extra data structures used)

*/



  // this code also correct but in this case we not handle the head null case so this code only for syntx learn for beginners

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
};
ListNode *reverseLL(ListNode *&head) {
  ListNode *prev = NULL;
  ListNode *curr = head;
  while (curr != NULL) {
    ListNode *forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
  }
  // new head
  return prev;
}

class Solution {
public:
  ListNode *plusOne(ListNode *head) {
    // Step1: reverse logic
    head = reverseLL(head);
    // Step2:add 1 logic
    int carry = 1;
    ListNode *temp = head;
    while (temp != NULL) {
      int val = temp->val;
      int sum = val + carry;

      int digit = sum % 10;
      carry = sum / 10;

      // insert digit into curr node
      temp->val = digit;
      if (temp->next == NULL && carry != 0) {
        // i need to create a extra node
        ListNode *newNode = new ListNode(carry);
        // link this node with temp
        temp->next = newNode;
        temp = newNode;
      }
      // move to next node,otherwise loop stuck
      temp = temp->next;
    }
    // Step3: again reverse to get the answer
    head = reverseLL(head);

    return head;
  }
};
