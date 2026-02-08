#include <iostream>
using namespace std;

/*

Example 1:

Input: head = [1,2,3,4,5,6,7,8], k = 3

Output: [3,2,1,6,5,4,8,7]

Explanation:
The first 3 nodes [1,2,3] are reversed to [3,2,1].
The next 3 nodes [4,5,6] are reversed to [6,5,4].
The final 2 nodes [7,8] are reversed to [8,7].
The reversed groups are then connected.

Example 2:

Input: head = [1,2,3,4,5], k = 2

Output: [2,1,4,3,5]

Explanation:
The groups are [1,2], [3,4], and [5]. They are reversed to [2,1], [4,3], and [5].

Input Format
The input is the head of the linked list and an integer k.

Output Format
Return the head of the modified linked list.

Example 1:

Input: n=6, k=5

Output: '88 60 0 92 35 52 '

Example 2:

Input: n=10, k=10

Output: '33 58 7 25 79 70 53 32 66 17 '

Example 3:

Input: n=4, k=3

Output: '17 3 24 93 '

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
    Node *reverseKGroup(Node *head, int k)
    {
        // step 1: check geoup of len k
        int count = 0;
        Node *temp = head;
        while (temp != NULL && count < k)
        {
            temp = temp->next;
            count++;
        }
        // if goup exist
        if (count == k)
        {
            // reverse 1 group and baaki recusion dekh lega
            Node *prev = NULL;
            Node *curr = head;
            Node *forward = NULL;

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
            Node *recusionHead = reverseKGroup(forward, k);
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

// short notes for this prblem

/*
🔹 Reverse Nodes in K-Group – Short Notes

📌 Problem:
Reverse a linked list in groups of size k.

📌 Approach (Steps):

Count k nodes from current head.

If k nodes exist → reverse first k nodes.

Call recursion for remaining list.

Connect reversed part with recursion result.

If less than k nodes remain → return list as it is.

📌 Key Pointers Used:

prev → previous node

curr → current node

forward → next node

📌 Base Case:

If k nodes not available → return head.

📌 Time Complexity: O(n)
📌 Space Complexity: O(n/k) (recursion stack)

📌 Example:
Input: 1→2→3→4→5, k=2
Output: 2→1→4→3→5

📌 Important Points:

Incomplete last group is not reversed.

Works for singly linked list.

Very common interview + DSA problem.

*/