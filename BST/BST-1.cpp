#include <iostream>
#include <limits.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node *buildBST(Node *root, int value)
{
    if (root == NULL)
    {
        root = new Node(value);
        return root;
    }
    else
    {
        if (value > root->data)
        {
            root->right = buildBST(root->right, value);
        }
        else
        {
            root->left = buildBST(root->left, value);
        }
        return root;
    }
}

Node *createBST(Node *root)
{
    cout << "Enter the value for the node" << endl;
    int val;
    cin >> val;
    // jab value -1 hogi tab rukna hai, agar val -1 nahi h toh mat ruko
    while (val != -1)
    {
        root = buildBST(root, val);
        cout << "Enter the value for the node" << endl;
        cin >> val;
    }
    return root;
}

void preorder(Node *root)
{
    // NLR;
    // base case
    if (root == NULL)
    {
        return;
    }
    // NLR
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    // LNR;
    // base case
    if (root == NULL)
    {
        return;
    }
    // LNR
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    // LRN;
    // base case
    if (root == NULL)
    {
        return;
    }
    // LRN
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelorderTraversal(Node *root)
{
    queue<Node *> q;
    // initial state maintain
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front == NULL)
        {
            // iska mtlb current level ki saari node travel ho chuki h
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
}

int getMin(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    // hum ek aisi node dhund rhe h, jiske left me kuch nahi h
    // and  we are only traversing leftwards
    while (root->left != NULL)
    {
        root = root->left;
    }
    // now, i am at the leftmost node
    return root->data;
}

int getMax(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    // now , u are at the rightmost node
    return root->data;
}

bool searchBST(Node *root, int target)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == target)
    {
        return true;
    }
    else
    {
        if (target > root->data)
        {
            // right me jao
            bool rightAns = searchBST(root->right, target);
            if (rightAns == true)
            {
                return true;
            }
        }
        if (target < root->data)
        {
            // left me jao
            bool leftAns = searchBST(root->left, target);
            if (leftAns == true)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    Node *root = NULL;
    root = createBST(root);
    cout << "Hello" << endl;
    cout << endl;
    cout << "Printing Preorder : ";
    preorder(root);

    cout << endl
         << "printing inorder: ";
    inorder(root);

    cout << endl
         << "printing postorder: ";
    postorder(root);

    cout << endl
         << "printing level order: " << endl;
    levelorderTraversal(root);

    cout << endl
         << "Printing MIn value: " << endl;
    cout << getMin(root) << endl;

    cout << endl
         << "Printing Max value: " << endl;
    cout << getMax(root) << endl;
    int target = 70;
    cout << "Searching target: " << searchBST(root, target) << endl;

    return 0;
}

//      100
//     /.  \
//   50.    150
//   /\.    / \
// 40  60. 120 180
// BST -> inorder  -> always sorted
