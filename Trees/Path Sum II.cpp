#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void solve(TreeNode *root, int target, int sum, vector<int> &temp, vector<vector<int>> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        // current node pr
        sum = sum + root->val;
        temp.push_back(root->val);
        // leaf node
        if (root->left == NULL && root->right == NULL)
        {
            if (sum == target)
            {
                ans.push_back(temp);
                temp.pop_back();
                return;
            }
        }
        solve(root->left, target, sum, temp, ans);
        solve(root->right, target, sum, temp, ans);
        // optional/mandatory if by reference
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        int sum = 0;
        vector<int> temp;
        vector<vector<int>> ans;
        solve(root, targetSum, sum, temp, ans);
        return ans;
    }
};