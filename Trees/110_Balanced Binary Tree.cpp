#include<iostream>
using namespace std;

/*     leetcode-110

Given a binary tree, determine if it is height-balanced.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

*/


  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
      
      int getHeight(TreeNode * root){
        if(root==NULL){
            return 0;
        }
        int leftDepth=getHeight(root->left);
        int rightDepth=getHeight(root->right);
        int ans=max(leftDepth,rightDepth)+1;
        return ans;
      }


    bool isBalanced(TreeNode* root) {
        //base case
        if(root==NULL){
            //empty tree ko main balanced hi manra hu 
            return true;     
               }
               //current node ka nas
               int leftHeight=getHeight(root->left);
               int rightHeight=getHeight(root->right);
               int absDiff=abs(leftHeight-rightHeight);
               if(absDiff>1){
                //not balanced 
                return false;
               }
               else{
                
                //current node toh pakka balanced hai 
                //baki recursion se solve karwa lunga 
                //leftAns
                bool leftAns=isBalanced(root->left);
                //rightAns
                bool rightAns=isBalanced(root->right);
                if(leftAns==true && rightAns==true){
                    return true;
                }
                else{
                    return false;
                }



               }


    }
};