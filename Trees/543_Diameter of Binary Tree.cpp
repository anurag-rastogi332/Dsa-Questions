#include<iostream>
using namespace std;


/*

You are given the root of a binary tree. Your task is to determine the length of the diameter of the tree.

The diameter of a binary tree is defined as the length of the longest path between any two nodes in the tree. This path does not necessarily pass through the root node.

The length of a path is represented by the number of edges between the two nodes.

Example
Consider the following binary tree:


        1
       / \
      2   3
     / \
    4   5
In this tree, the longest path is the path that goes through the nodes 4, 2, 1, 3 or 5, 2, 1, 3. The length of this path is 3, as it involves 3 edges. Hence, the diameter of this tree is 3.

Example 1:

Input:

root = [1, 2, 3, 4, 5]

Output:

3
Explanation:The diameter is the path [4 -> 2 -> 1 -> 3] or [5 -> 2 -> 1 -> 3] with length 3.

Example 2:

Input:

root = [1, 2]

Output:

1
Explanation:The diameter is the path [2 -> 1] with length 1.

Example 3:

Input:

root = [1, 2, 3, null, 4, null, 5]

Output:

4
Explanation:The longest path is [4 -> 2 -> 1 -> 3 -> 5] with length 4.

Constraints

The number of nodes in the tree is in the range [1, 104].
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
    int leftheight = maxDepth(root->left) + 1;
    int rightheight = maxDepth(root->right) + 1;
    int ans = max(leftheight, rightheight);
    return ans;
  }

  int diameterOfBinaryTree(TreeNode *root) {
    // base case
    if (root == NULL) {
      return 0;
    }
    // LST+ROOT+RST
    int option1 = maxDepth(root->left) + maxDepth(root->right);
    int option2 = diameterOfBinaryTree(root->left);
    int option3 = diameterOfBinaryTree(root->right);
    int ans = max(option1, max(option2, option3));
    return ans;
  }
};
