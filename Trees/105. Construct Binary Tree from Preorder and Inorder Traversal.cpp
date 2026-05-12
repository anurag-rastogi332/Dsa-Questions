#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.



Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]


Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder,
                        int &preorderIndex, int inorderStart, int inorderEnd, unordered_map<int, int> &mp)
    {

        // base case
        if (preorderIndex >= preorder.size())
        {
            return NULL;
        }

        if (inorderStart > inorderEnd)
        {
            return NULL;
        }

        // main logic
        int element = preorder[preorderIndex];
        preorderIndex++;

        TreeNode *root = new TreeNode(element);

        int elementIndexInsideInorder = mp[element];

        // recursive calls
        root->left = buildTree(preorder, inorder, preorderIndex, inorderStart, elementIndexInsideInorder - 1, mp);
        root->right = buildTree(preorder, inorder, preorderIndex, elementIndexInsideInorder + 1, inorderEnd, mp);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        int preorderIndex = 0;
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;
        TreeNode *root = buildTree(preorder, inorder, preorderIndex, inorderStart, inorderEnd, mp);

        return root;
    }
};