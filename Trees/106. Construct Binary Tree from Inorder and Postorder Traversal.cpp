#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.



Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]


Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int &postIndex, unordered_map<int, int> &mp)
    {
        if (postIndex < 0)
        {
            return NULL;
        }
        if (inStart > inEnd)
        {
            return NULL;
        }
        // main logic

        int element = postorder[postIndex];
        postIndex--;
        TreeNode *root = new TreeNode(element);
        int elementIndexInsideInorder = mp[element];
        root->right = buildTree(inorder, postorder, elementIndexInsideInorder + 1, inEnd, postIndex, mp);
        root->left = buildTree(inorder, postorder, inStart, elementIndexInsideInorder - 1, postIndex, mp);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        int inStart = 0;
        int inEnd = inorder.size() - 1;
        int postIndex = postorder.size() - 1;
        TreeNode *root = buildTree(inorder, postorder, inStart, inEnd, postIndex, mp);
        return root;
    }
};