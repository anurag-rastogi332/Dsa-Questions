#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []

*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class compare
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, compare> pq;

        ListNode *head = NULL;
        ListNode *tail = NULL;

        int totalRows = lists.size();
        // first k element process
        // first element of every list
        for (int i = 0; i < totalRows; i++)
        {
            ListNode *first = lists[i];
            if (first != NULL)
            {
                pq.push(first);
            }
        }

        // main logic
        while (!pq.empty())
        {
            ListNode *front = pq.top();
            pq.pop();

            // ans me store karlo front ko
            // this can be your first node or cannot be
            if (head == NULL && tail == NULL)
            {
                head = front;
                tail = front;
            }
            else
            {
                tail->next = front;
                tail = front;
            }

            /// new node from the same LL insert karo
            if (front->next != NULL)
            {
                pq.push(front->next);
            }
        }
        return head;
    }
};