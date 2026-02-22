#include <iostream>
using namespace std;

// gfg -> https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree/0

/*

Given a Binary Tree of size n, You have to count leaves in it. For example, there are two leaves in the following tree




Examples:

Input:
Given Tree is

Output: 3
Explanation: Three leaves are 3, 5 and 1.
Input:
Given Tree is

Output: 4
Explanation: Four leaves are 20, 40, 65 and 80.
Input:
Given Tree is

Output: 3
Explanation: Three leaves are 20, 27 and 40.

*/

/*A binary tree node has data, pointer to left child
   and a pointer to right child*/

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Class Solution
class Solution
{

    void countL(Node *root, int &c)
    {
        if (root == NULL)
        {
            return;
        }
        // if(root->left==null &&root->right==null) then count
        if (root->left == NULL && root->right == NULL)
        {
            c++;
        }
        countL(root->left, c);
        countL(root->right, c);
    }

public:
    int countLeaves(Node *root)
    {
        int c = 0;

        countL(root, c);
        return c;
    }
};