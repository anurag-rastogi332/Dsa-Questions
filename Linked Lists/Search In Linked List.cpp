#include <iostream>
using namespace std;

/*


Input: LinkedList: 1->2->3->4->5, x = 4
Output: 1
Input: LinkedList: 2->4->6->7->5->1->0, x = 10
Output: 0

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
    bool searchLinkedList(Node *head, int x)
    {
        // Your code here
        while (head != NULL)
        {
            if (head->data == x)
            {
                return true;
            }
            head = head->next;
        }
        return false;
    }
};