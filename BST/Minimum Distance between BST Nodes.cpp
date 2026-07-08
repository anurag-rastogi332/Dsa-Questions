#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*

Example 1: Input: root = [4,2,6,1,3] This represents the following tree structure:


      4
     / \
    2   6
   / \
  1   3
Output: 1 Explanation: The node values in sorted order, obtained by an in-order traversal, are [1, 2, 3, 4, 6]. The absolute differences between adjacent values in this sorted list are:

|2 - 1| = 1
|3 - 2| = 1
|4 - 3| = 1
|6 - 4| = 2 The minimum among these differences is 1.
Example 2: Input: root = [1,0,48,null,null,12,49] This represents the following tree structure:


      1
     / \
    0   48
       /  \
      12   49
Output: 1 Explanation: The node values in sorted order are [0, 1, 12, 48, 49]. The absolute differences between adjacent values in this sorted list are:

|1 - 0| = 1
|12 - 1| = 11
|48 - 12| = 36
|49 - 48| = 1 The minimum among these differences is 1.

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
    void inorder(TreeNode *root, vector<int> &st)
    {
        if (root == NULL)
        {
            return;
        }
        // L->ROOT->R
        inorder(root->left, st);
        // ek case mai solve karunga
        st.push_back(root->val);
        inorder(root->right, st);
    }

    int minDiffInBST(TreeNode *root)
    {
        vector<int> st;
        inorder(root, st);
        int min = INT_MAX;
        for (int i = 0; i < st.size() - 1; i++)
        {
            int difference = st[i + 1] - st[i];
            if (difference < min)
            {
                min = difference;
            }
        }
        return min;
    }
};