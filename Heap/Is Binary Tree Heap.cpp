#include <iostream>
#include <queue>
using namespace std;

//  https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    bool isCompleteTree(Node *root)
    {
        queue<Node *> q;
        // intial statte
        q.push(root);
        bool nullFound = false;
        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();
            if (front == NULL)
            {
                nullFound = true;
            }
            else
            {
                if (nullFound == true)
                {
                    return false;
                }
                q.push(front->left);
                q.push(front->right);
            }
        }
        return true;
    }
    bool checkMaxHeapProperty(Node *root)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }

        bool leftAns = checkMaxHeapProperty(root->left);
        bool rightAns = checkMaxHeapProperty(root->right);
        // bss current node ko check krna pending h
        // case1: left node exist and right node does not exist
        // case 2 : left node does notexist, right node exits
        // case 3: left and right both exists
        // we are checking for current node here
        bool leftNodeCheck = true;
        bool rightNodeCheck = true;
        if (root->left && root->left->data > root->data)
        {
            leftNodeCheck = false;
        }
        if (root->right && root->right->data > root->data)
        {
            rightNodeCheck = false;
        }
        bool currentNodeAns = leftNodeCheck && rightNodeCheck;
        if (currentNodeAns && leftAns && rightAns)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isHeap(Node *tree)
    {
        // code here
        // I have to check for 2 conditions:
        // CBT property
        bool cbtOrNot = isCompleteTree(tree);
        // Heap Specific Property - Max Heap
        bool validHeapProperty = checkMaxHeapProperty(tree);
        // if both are true then its a vlid heap
        return cbtOrNot && validHeapProperty;
    }
};