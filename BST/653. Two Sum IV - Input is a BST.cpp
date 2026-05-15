#include <iostream>
#include <vector>
using namespace std;

/*

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.



Example 1:


Input: root = [5,3,6,2,4,null,7], k = 9
Output: true
Example 2:


Input: root = [5,3,6,2,4,null,7], k = 28
Output: false


Constraints:

The number of nodes in the tree is in the range [1, 104].
-104 <= Node.val <= 104
root is guaranteed to be a valid binary search tree.
-105 <= k <= 105

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
    void storeInorder(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
        {
            return;
        }
        storeInorder(root->left, inorder);
        inorder.push_back(root->val);
        storeInorder(root->right, inorder);
    }

    bool checkTwoSum(vector<int> &arr, int target)
    {
        int n = arr.size() - 1;
        int s = 0;
        int e = n;
        while (s < e)
        {
            long long int sum = arr[s] + arr[e];
            if (sum == target)
                return true;
            if (sum < target)
                s++;
            if (sum > target)
                e--;
        }
        return false;
    }

    bool findTarget(TreeNode *root, int k)
    {
        vector<int> inorder;
        storeInorder(root, inorder);
        bool ans = checkTwoSum(inorder, k);
        return ans;
    }
};