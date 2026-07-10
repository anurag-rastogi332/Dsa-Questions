#include <iostream>
#include <queue>
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

class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        // level order wise travvel
        // rule:
        // if there iexists any elemnt after NULL, then not CBT
        // if there exists no elemnt after NULL, then its a CBT
        queue<TreeNode *> q;
        // intial statte
        q.push(root);
        bool nullFound = false;
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if (front == NULL)
            {
                nullFound = true;
            }
            else
            {
                // agar ye valid element se phle kabhi null mila tha
                //  iska mtlb CBT nahi h
                if (nullFound == true)
                {
                    return false;
                }
                // mujhe ek valid element mila h
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
};