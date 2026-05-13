#include <iostream>
#include <vector>
using namespace std;

/*

Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.



Example 1:


Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:


Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.


Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in a strictly increasing order.

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
    TreeNode *solve(vector<int> &inorder, int s, int e)
    {
        if (s > e)
        {
            return NULL;
        }
        int mid = s + (e - s) / 2;
        int element = inorder[mid];
        TreeNode *root = new TreeNode(element);
        root->left = solve(inorder, s, mid - 1);
        root->right = solve(inorder, mid + 1, e);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {

        int start = 0;
        int end = nums.size() - 1;
        TreeNode *root = solve(nums, start, end);
        return root;
    }
};