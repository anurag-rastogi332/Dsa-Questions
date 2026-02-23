#include<iostream>
using namespace std;


    
/*  gfg->  https://www.geeksforgeeks.org/problems/root-to-leaf-path-sum/1

Given a binary tree and an integer target, check whether there is a root-to-leaf path with its sum as target.

Examples :

Input: target = 2
   1 
 /   \
2     3
Output: false
Explanation: There is no root to leaf path with sum 2.
Input: target = 4
   1
 /   \
2     3
Output: true
Explanation: The sum of path from leaf node 3 to root 1 is 4.
Constraints:
1 ≤ number of nodes ≤ 104
1 ≤ target ≤ 106

*/



// A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; 

/*you are required to
complete this function */
class Solution {
  public:
      bool solve(Node *root,int target,int sum){
          //base case
          if(root==NULL){
              return false;
          }
          //current node-1 case
          sum=sum+root->data;
          //if a lead node then check for taget 
          if(root->left==NULL && root->right==NULL){
              if(sum==target){
                  return true;
              }
              else{
                  return false;
              }
          }
          //baaki recursion 
          bool leftAns=solve(root->left,target,sum);
          bool rightAns=solve(root->right,target,sum);
          return leftAns||rightAns;
      }
  
    bool hasPathSum(Node *root, int target) {
        int sum=0;
        bool ans=solve(root,target,sum);
        return ans;
        
    }
};