#include <iostream>
#include <vector>
using namespace std;

/*

Example 1:


      1
     / \
    2   3
   / \   \
  4   5   6
     /
    7
Looking from the left:

At level 0, only node 1 is visible.
At level 1, node 2 is visible (node 3 is to its right).
At level 2, node 4 is visible (nodes 5 and 6 are to its right or further right).
At level 3, node 7 is visible.
The left view of the tree is [1, 2, 4, 7].

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
    void left(TreeNode *root, int level, vector<int> &v)
    {
        if (root == NULL)
        {
            return;
        }
        if (v.size() == level)
        {
            v.push_back(root->val);
        }
        left(root->left, level + 1, v);
        left(root->right, level + 1, v);
    }

    vector<int> leftView(TreeNode *root)
    {
        vector<int> v;
        left(root, 0, v);
        return v;
    }
};