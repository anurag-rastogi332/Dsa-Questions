#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*

Example 1: Valid Max-Heap

Input Tree:

      10
     /  \
    9    8
   / \  /
  7   6 5
  
Output: true Explanation:

Shape Property: The tree is a complete binary tree. All levels are filled except the last, and the nodes on the last level (7, 6, 5) are as far left as possible.
Heap Property:
Node 10 (10 >= 9, 10 >= 8)
Node 9 (9 >= 7, 9 >= 6)
Node 8 (8 >= 5)
Leaf nodes (7, 6, 5) trivially satisfy the property. Both properties are satisfied.

*/

class Solution
{
public:
    bool checkComplete(TreeNode *root)
    {
        queue<TreeNode *> que;
        que.push(root);
        bool past = false; // check kr rahe ki ki past me humne koi null node
                           // dekhi hai kya
        while (!que.empty())
        {
            TreeNode *node = que.front();
            que.pop();
            if (node == NULL)
            {
                past = true;
            }
            else
            {
                if (past == true)
                {
                    return false;
                }
                que.push(node->left);
                que.push(node->right);
            }
        }
        return true;
    }

    bool checkHeap(TreeNode *root)
    {
        if (root == NULL)
            return true;

        if (root->left != NULL)
        {
            if (root->val < root->left->val)
                return false;
        }

        if (root->right != NULL)
        {
            if (root->val < root->right->val)
                return false;
        }

        return checkHeap(root->left) && checkHeap(root->right);
    }

    bool isBinaryTreeHeap(TreeNode *root)
    {
        return checkComplete(root) && checkHeap(root);
    }
};