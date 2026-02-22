#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        // base case
        if (root == NULL)
        {
            return 0;
        }
        int leftheight = maxDepth(root->left) + 1;
        int rightheight = maxDepth(root->right) + 1;
        int ans = max(leftheight, rightheight);
        return ans;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        // base case
        if (root == NULL)
        {
            return 0;
        }
        // LST + ROOT + RST
        int option1 = maxDepth(root->left) + maxDepth(root->right);
        int option2 = diameterOfBinaryTree(root->left);
        int option3 = diameterOfBinaryTree(root->right);
        int ans = max(option1, max(option2, option3));
        return ans;
    }
};