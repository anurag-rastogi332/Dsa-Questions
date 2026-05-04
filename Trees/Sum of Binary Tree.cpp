#include <iostream>
using namespace std;

/*

Examples:

Input: root = [15, 10, 20, 8, 12, 16, 25]

Output: 106
Explanation: The sum of all the nodes is 15 + 10 + 20 + 8 + 12 + 16 + 25 = 106
.
Input: root = [1, 3, 2]

Output: 6
Explanation: The sum of all the nodes is 1 + 2 + 3 = 6.
Input: root = [1, 2, N, 4, N]

Output: 7
Explanation: The sum of all the nodes is 1 + 2 + 4 = 7.
Constraints:
1 ≤ number of nodes ≤ 104
-105 ≤ Node data ≤ 105

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

    void sumSolve(Node *root, int &sum)
    {
        if (root == NULL)
        {
            return;
        }

        sum += root->data;
        sumSolve(root->left, sum);
        sumSolve(root->right, sum);
    }

public:
    int sumBT(Node *root)
    {
        int sum = 0;
        sumSolve(root, sum);
        return sum;
    }
};
