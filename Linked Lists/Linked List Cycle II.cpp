#include <iostream>
using namespace std;
#include <unordered_map>
// Leetcode-> https://leetcode.com/problems/linked-list-cycle-ii/

/*
Example 1:

Input: head = [3,2,0,-4], pos = 1

Output: Node at index 1 (the node with value 2)

Explanation: The cycle begins at the node with value 2.

Example 2:

Input: head = [1,2], pos = 0

Output: Node at index 0 (the node with value 1)

Explanation: The cycle begins at the head node.

Input Format The input is the head of the linked list.

Output Format Return the ListNode where the cycle begins. If there is no cycle, return null.

Example 1:

Input: head = [45255,-30338,83075,-98775,18869,74418], pos = 5

Output: '74418'

Example 2:

Input: head = [-66084,32317,-36613,5734,40272,57704,-48938,-85180,14885,-34028], pos = -1

Output: 'null'

Example 3:

Input: head = [-52352,-93806,-65599,85725,93219,-96050], pos = 4

Output: '93219'

*/

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_map<ListNode *, bool> visited;

        ListNode *temp = head;
        while (temp != NULL)
        {
            if (visited[temp] == true)
            {
                return temp;
            }
            else
            {
                visited[temp] = true;
                temp = temp->next;
            }
        }
        // agar main yaha tak aa gaya
        // iska mtlb temp==NULL hoga
        //  no loop
        return NULL;
    }
};

// this is not a good solution check second solution