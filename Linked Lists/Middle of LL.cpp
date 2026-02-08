#include <iostream>
using namespace std;
/*

Examples:

Input:

Output: 3
Explanation: The given linked list is 1->2->3->4->5 and its middle is 3.

Input:

Output: 7
Explanation: The given linked list is 2->4->6->7->5->1 so, there are two middle node 6 and 7, return the second middle node as 7.


*/

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    int getMiddle(Node *head)
    {
        if (head == NULL)
        {
            return -1;
        }
        Node *slow = head;
        Node *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }
};