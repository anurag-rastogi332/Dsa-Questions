#include<iostream>
using namespace std;

/*

Example 1:

Input: head = [1,2,3,4]

Output: [2,1,4,3]

Explanation:



Example 2:

Input: head = []

Output: []

Example 3:

Input: head = [1]

Output: [1]

Example 4:

Input: head = [1,2,3]

Output: [2,1,3]

 


*/




  
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *first=head;
        ListNode *sec=head->next;
        ListNode *prev=NULL;
        while(first!=NULL && sec!=NULL){
            ListNode *third=sec->next;
            sec->next=first;
            first->next=third;
            if(prev!=NULL){
                prev->next=sec;
            }
            else{
                head=sec;
            }
            prev=first;
            first=third;
            if(third!=NULL){
                sec=third->next;
            } 
            else{
                sec=NULL;
            }

        }
        return head;
    }
};