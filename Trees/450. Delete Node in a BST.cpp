#include <iostream>
using namespace std;

/*

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.


Example 1:


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 104].
-105 <= Node.val <= 105
Each node has a unique value.
root is a valid binary search tree.
-105 <= key <= 105


Follow up: Could you solve it with time complexity O(height of tree)?

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
    int getMax(TreeNode *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        while (root->right != NULL)
        {
            root = root->right;
        }
        return root->val;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->val == key)
        {
            // target/key mathch
            // 4 case
            // delete node with
            // 1-> 0 child
            if (root->left == NULL && root->right == NULL)
            {
                TreeNode *temp = root;
                delete temp;
                return NULL;
            }
            // 2-> 1 child-left
            if (root->left != NULL && root->right == NULL)
            {
                TreeNode *temp = root;
                TreeNode *child = root->left;
                temp->left = NULL;
                delete temp;
                return child;
            }
            // 3-> 1 child-right
            if (root->left == NULL && root->right != NULL)
            {
                TreeNode *temp = root;
                TreeNode *child = root->right;
                temp->right = NULL;
                delete temp;
                return child;
            }
            // 4-> 2 child
            if (root->left != NULL && root->right != NULL)
            {
                // first we will replace the "node to delete with the max value in its left subtree"
                // after that we will call the delete function on left subtree for the replaced value;
                // 1st step replacement
                int replaceValue = getMax(root->left);
                root->val = replaceValue;
                // 2nd step deletion
                root->left = deleteNode(root->left, replaceValue);
                return root;
            }
        }
        else
        {
            // no match
            if (key < root->val)
            {
                // deletion right side me krenge
                root->left = deleteNode(root->left, key);
            }
            else
            {
                // deletion left side me krenge
                root->right = deleteNode(root->right, key);
            }
        }
        return root;
    }
};