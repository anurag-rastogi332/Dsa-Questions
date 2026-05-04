#include <iostream>
using namespace std;

/*

Given the root of a binary tree, return the size of the tree. The size of a binary tree is the total number of nodes in the tree.

Examples:

Input:

Output:  3
Explanation: There are 3 nodes in the given binary tree, so its size is 3.
Input:

Output: 6
Explanation: There are 6 nodes in the given binary tree, so its size is 6.
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105

*/

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution
{

    void pre(Node *root, int &c)
    {
        if (root == NULL)
        {
            return;
        }
        c++;
        pre(root->left, c);
        pre(root->right, c);
    }

public:
    int getSize(Node *node)
    {

        int c = 0;
        pre(node, c);

        return c;
    }
};