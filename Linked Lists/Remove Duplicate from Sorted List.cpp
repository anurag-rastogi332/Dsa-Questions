#include <iostream>
using namespace std;

/*

Example 1:

Input: head = [1,1,2]

Output: [1,2]

Example 2:

Input: head = [1,1,2,3,3]

Output: [1,2,3]

Input Format The input is the head of the sorted linked list.

Output Format Return the head of the linked list after removing all duplicates.

Example 1:

Input:

head = [1,1,2]

Output:

1 2
Explanation:The sorted list [1,1,2] is processed to remove consecutive duplicates.

Example 2:

Input: head = [1,1,2,3,3]

Output: '1 2 3 '

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        // check empty linedlist
        if (head == NULL)
        {
            return head;
        }
        // signle node linkedlist
        if (head->next == NULL)
        {
            return head;
        }
        // main logic
        // yaha tak aaya hu iska mtlb kam kam se 2 nodes to jarur hongi linkedlist
        // me
        ListNode *prev = head;
        ListNode *curr = head->next;
        while (curr != NULL)
        {
            if (curr->val != prev->val)
            {
                curr = curr->next;
                prev = prev->next;
            }
            else
            {
                // if val are equal
                prev->next = curr->next;
                curr->next = NULL;
                delete curr;
                // reinitialise curr
                curr = prev->next;
            }
        }
        return head;
    }
};

/*

🔹 Delete Duplicates (Sorted Linked List) – Short Notes

📌 Core Logic (Few Lines):

Do pointers use karo: prev (unique node) aur curr (next node).

Agar curr->val != prev->val → dono pointers ko aage badhao.

Agar values same ho → duplicate node ko list se hatao (prev->next = curr->next) aur memory free karo.

curr ko prev->next se update karke traversal continue rakho.

📌 Important Assumption:

Linked list sorted hai, isliye duplicates adjacent milte hain.

📌 Time Complexity: O(n)
📌 Space Complexity: O(1)

*/