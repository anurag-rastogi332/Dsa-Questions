#include <iostream>
using namespace std;

/*

Example 1:

Input: head = [3,2,0,-4], pos = 1

Output: true

Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:

Input: head = [1,2], pos = 0

Output: true

Explanation: There is a cycle where the tail connects to the 0th node.

Input Format
The input is the head of the linked list.

Output Format
Return true if the linked list contains a cycle, otherwise return false.

Example 1:

Input: head = [45255,-30338,83075,-98775,18869,74418], pos = 5

Output: 'true'

Example 2:

Input: head = [-66084,32317,-36613,5734,40272,57704,-48938,-85180,14885,-34028], pos = -1

Output: 'false'

Example 3:

Input: head = [-52352,-93806,-65599,85725,93219,-96050], pos = 4

Output: 'true'
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
    bool hasCycle(ListNode *head)
    {

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

/*

🔹 Floyd’s Cycle Detection – Short Notes (Algorithm)

📌 Problem:
Detect whether a linked list contains a cycle.

📌 Idea (Core Concept):
Use two pointers:

slow moves 1 step at a time

fast moves 2 steps at a time
If there is a cycle, both pointers will meet inside the loop.

📌 Algorithm (Steps):

Initialize slow = head, fast = head.

While fast != NULL and fast->next != NULL:

slow = slow->next

fast = fast->next->next

If slow == fast, return true (cycle found).

If loop ends, return false (no cycle).

📌 Base Condition / Safety:
Loop condition ensures safe two-step jump and avoids crash.

📌 Time Complexity: O(n)
📌 Space Complexity: O(1) (no extra memory)

📌 Why Better than Map Method?
No extra space, faster in practice, interview-preferred approach.

🔹 Where This Algorithm Is Used (Applications / Questions)

Ye slow–fast pointer technique sirf cycle detect karne ke liye nahi, bahut jagah use hoti hai:

✅ 1️⃣ Detect Cycle in Linked List

Question: “Check if a linked list has a loop.”

Direct application of Floyd’s algorithm.

✅ 2️⃣ Find Starting Point of Cycle

Question: “Return the node where the cycle begins.”

Trick: After meeting point, move one pointer to head; move both 1 step — they meet at cycle start.

✅ 3️⃣ Find Length of Cycle

Question: “Find the length of the loop in linked list.”

Trick: Meeting point se ek full round lagakar count karo.

✅ 4️⃣ Middle of Linked List

Question: “Find middle element of linked list.”

Trick: Same slow–fast idea (fast 2 steps, slow 1 step).

✅ 5️⃣ Check Palindrome Linked List

Middle find karne ke baad second half reverse karke compare.

✅ 6️⃣ Happy Number Problem

Numbers pe cycle detect karna (slow–fast pointer on generated sequence).

✅ 7️⃣ Detect Cycle in Array (Functional Graph)

Question: “Find duplicate number” (Floyd’s algorithm on indices as pointers).

*/