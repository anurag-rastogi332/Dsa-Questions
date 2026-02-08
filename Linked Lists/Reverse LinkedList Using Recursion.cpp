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

struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

Node *reverseLLRecursive(Node *head, Node *prev)
{

    // Base Case
    if (head == NULL)
    {
        return prev;
    }

    // 1 case I will solve
    Node *curr = head;
    Node *forward = curr->next;

    curr->next = prev;

    // Remaining recursion will handle
    return reverseLLRecursive(forward, curr);
}

// Function call syntax to reverse linked list recursively:
// newHead = reverseLLRecursive(head, NULL);
