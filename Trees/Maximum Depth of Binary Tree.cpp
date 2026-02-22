#include<iostream>
using namespace std;

/*

Given the root of a binary tree, your task is to find the maximum depth of the tree.

The maximum depth of a binary tree is defined as the number of nodes present along the longest path from the root node all the way down to the farthest leaf node. A leaf node is a node with no children.

Example:
Consider the following binary tree:


      3
     / \
    9   20
        /  \
       15   7
The maximum depth of the binary tree shown above is 3, because the longest path is: 3 -> 20 -> 7.

Note:
The binary tree can be empty. In such a case, its depth is 0.
Example 1:

Input:

root = [3, 9, 20, null, null, 15, 7]

Output:

3
Explanation:Standard level order traversal for a three-level tree.

Example 2:

Input:

root = [3, 9, 20, null, null, 15, 7]

Output:

3
Explanation:Standard level order traversal for a three-level tree.

Example 3:

Input:

root = [3, 9, 20, null, null, 15, 7]

Output:

3
Explanation:Standard level order traversal for a three-level tree.

Constraints

The number of nodes in the tree is in the range [0, 10^4].
-100 <= Node.val <= 100

*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    int ledtheight = maxDepth(root->left) + 1;
    int rightheight = maxDepth(root->right) + 1;
    int ans = max(ledtheight, rightheight);
    return ans;
  }
};