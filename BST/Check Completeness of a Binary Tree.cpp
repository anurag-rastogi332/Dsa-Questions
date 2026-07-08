#include <iostream>
#include <queue>
using namespace std;

/*

Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.

*/

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
    bool checkComplete(TreeNode *root)
    {
        queue<TreeNode *> que;
        que.push(root);
        bool past = false; // check kr rahe ki ki past me humne koi null node dekhi hai kya
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
    };

    bool isCompleteTree(TreeNode *root)
    {
        return checkComplete(root);
    }
};