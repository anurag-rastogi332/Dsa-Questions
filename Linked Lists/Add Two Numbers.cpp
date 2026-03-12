#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *ans(ListNode *l1, ListNode *l2)
    {
        ListNode *FinalAns = new ListNode(0);
        ListNode *temp = FinalAns;

        //  ListNode *Final=new ListNode;
        int carry = 0;

        while (l1 || l2 || carry)
        {
            int sum = 0;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            // yaha pe mere me dono node ka sum aa gaya ab mai isme carry add karun
            sum = carry + sum;
            // yaha pe mera carry aur sun aa gaya
            // isko mai new node me add kr dunga
            //  bo bhi mai sum%10 ko add kaunga
            //  aur sum/10 ko mai carry me add kr dunga
            carry = sum / 10;
            ListNode *newNode = new ListNode(sum % 10);
            temp->next = newNode;
            temp = temp->next;
        }
        return FinalAns->next;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        return ans(l1, l2);
    }
};