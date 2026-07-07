#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Info
{
public:
    int minVal;
    int maxVal;
    int sum;
    bool isBST;
};

class Solution
{
public:
    Info solve(TreeNode *root, int &sum)
    {
        if (root == NULL)
        {
            Info temp;
            temp.minVal = INT_MAX;
            temp.maxVal = INT_MIN;
            temp.sum = 0;
            temp.isBST = true;
            return temp;
        }
        // LRN
        Info leftAns = solve(root->left, sum);
        Info rightAns = solve(root->right, sum);
        // N
        Info currentAns;
        currentAns.minVal = min(root->val, min(leftAns.minVal, rightAns.minVal));
        currentAns.maxVal = max(root->val, max(leftAns.maxVal, rightAns.maxVal));
        currentAns.sum = root->val + leftAns.sum + rightAns.sum;
        currentAns.isBST = false;
        // check whether its true or not
        if (root->val > leftAns.maxVal && root->val < rightAns.minVal && leftAns.isBST && rightAns.isBST)
        {
            currentAns.isBST = true;
            // if it is a valid st ,then we update the sum
            sum = max(sum, currentAns.sum);
        }
        else
        {
            currentAns.isBST = false;
        }
        return currentAns;
    }

    int maxSumBST(TreeNode *root)
    {
        int sum = 0;
        Info ans = solve(root, sum);
        return sum;
    }
};