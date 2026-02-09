#include <iostream>
using namespace std;

/*


Example 1:

Input: head = [1,2,2,0,1]

Output: [0,1,1,2,2]

Input Format
The input is the head of the linked list.

Output Format
Return the head of the sorted linked list.

Example 1:

Input:

head = [1,2,2,0,1]

Output:

0 1 1 2 2
Explanation:The list [1,2,2,0,1] is sorted by node values.

Example 2:

Input: head = [0,0,0]

Output: '0 0 0 '

Example 3:

Input: head = [1,1,1]

Output: '1 1 1 '

*/

struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

class Solution
{
public:
    void insertAtTail(Node *&toInsert, Node *&head, Node *&tail)
    {
        // toInsert->node to insert
        // head->0/1/2 wali linked list ka head
        // tail 0/1/2 wali linked list ka tail
        if (head == NULL && tail == NULL)
        {
            head = toInsert;
            tail = toInsert;
        }
        else
        {
            tail->next = toInsert;
            tail = toInsert;
        }
    }

    Node *sortList(Node *head)
    {

        // case: empty linked list
        if (head == NULL)
        {
            return NULL;
        }

        Node *zeroHead = NULL;
        Node *zeroTail = NULL;

        Node *oneHead = NULL;
        Node *oneTail = NULL;

        Node *twoHead = NULL;
        Node *twoTail = NULL;

        Node *temp = head;
        while (temp != NULL)
        {

            // her node ko isolate krna hai aur appropriate ll me add krna hai
            Node *toInsert = temp;
            temp = temp->next;
            toInsert->next = NULL;

            // appropriate ll me insert krna hai
            if (toInsert->data == 0)
            {
                insertAtTail(toInsert, zeroHead, zeroTail);
            }

            // appropriate ll me insert krna hai
            if (toInsert->data == 1)
            {
                insertAtTail(toInsert, oneHead, oneTail);
            }

            // appropriate ll me insert krna hai
            if (toInsert->data == 2)
            {
                insertAtTail(toInsert, twoHead, twoTail);
            }
        }

        // kya temp ko aage badane ki need hai answer is no becase humne alrady
        // line no.37 per temp ko aage badha diya hai

        // i can say out three list are completed
        // merge all three lists
        if (zeroHead != NULL)
        {
            if (oneHead != NULL)
            {
                // connect zero ;; with one ll
                zeroTail->next = oneHead;
                oneTail->next = twoHead;
                return zeroHead;
            }
            else
            {
                // onehead==NULL;
                zeroTail->next = twoHead;
                return zeroHead;
            }
        }

        else
        {
            // zerohead==null
            if (oneHead != NULL)
            {
                oneTail->next = twoHead;
                return oneHead;
            }
            else
            {
                // onehead ==null
                return twoHead;
            }
        }
    }
};

// Algorithm: Sort a linked list containing only 0, 1, and 2
// --------------------------------------------------------
// 1) Create three separate lists for values 0, 1, and 2.
//    - Maintain both head and tail for each list to allow O(1) insertion.
//
// 2) Traverse the original linked list once.
//    - For each node:
//      a) Detach the node from the original list (save next, set node->next = NULL).
//      b) Append the node to the corresponding list (0-list, 1-list, or 2-list).
//
// 3) Merge the three lists in order: 0-list -> 1-list -> 2-list.
//    - Carefully handle cases where any of the lists may be empty.
//
// 4) Return the head of the merged list.
//
// Key Properties:
// - Time Complexity: O(n)  (single traversal + constant-time merges)
// - Space Complexity: O(1) (in-place rearrangement, no extra nodes created)
//
// Edge Cases:
// - If head == NULL: return NULL (early return).
// - If only one of the lists is non-empty, return that list directly.
//
// Reusable Pattern (For Similar Problems):
// - Partition list into k groups based on a condition.
// - Maintain (head, tail) for each group.
// - Reconnect groups in the required order.
// - This pattern applies to: partition by value, odd-even lists, stable grouping, etc.
