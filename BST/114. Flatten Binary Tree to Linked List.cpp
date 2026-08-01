#include <iostream>
#include <vector>
using namespace std;

/*

Example 1:


Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [0]
Output: [0]

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
    void preorder(TreeNode *root, vector<TreeNode *> &v)
    {
        if (root == NULL)
        {
            return;
        }
        v.push_back(root);
        preorder(root->left, v);
        preorder(root->right, v);
    }
    void flatten(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        vector<TreeNode *> v;
        preorder(root, v);
        for (int i = 0; i < v.size() - 1; i++)
        {
            v[i]->left = NULL;
            v[i]->right = v[i + 1];
        }
        v.back()->left = NULL;
        v.back()->right = NULL;
    }
};