#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000

*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // final answer store karne ke liye
        vector<vector<int>> ans;
        // empty tree
        if (root == NULL)
        {
            return {};
        }
        // LOT
        queue<TreeNode *> q;
        // initial state maintain
        q.push(root);
        // using NULL as a marker
        q.push(NULL);
        // current level ka data store karne ke liye
        vector<int> temp;
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            // NULL means ek level complete ho gaya
            if (front == NULL)
            {
                // current level ko ans me daaldo
                ans.push_back(temp);
                // next level ke liye temp ko empty kardo
                temp.clear();
                // agar q empty h, then do not insert NULL
                // infinite loop me fas skte h
                // agar q non empty h, then insert NULL
                // taaki next level ka end mark ho sake
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                // current node ka data temp me store karlo
                temp.push_back(front->val);

                // left child exist karta h
                // to q me push kardo
                if (front->left != NULL)
                {
                    q.push(front->left);
                }
                // right child exist karta h
                // to q me push kardo
                if (front->right != NULL)
                {
                    q.push(front->right);
                }
            }
        }
        // final answer return
        return ans;
    }
};