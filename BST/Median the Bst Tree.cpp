#include<iostream>
#include<vector>
using namespace std;




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
    void store(TreeNode *root,vector<int>&ans){
        //edge case
         if(root==NULL) return;
         store(root->left,ans); 
        //1st case mai solve karunga  
          ans.push_back(root->val);
          //recursion
          store(root->right,ans);
    } 

    double findMedian(TreeNode* root) {
        vector<int>ans;
        store(root,ans);
        int n=ans.size();
        return ans[n/2];
    }
};