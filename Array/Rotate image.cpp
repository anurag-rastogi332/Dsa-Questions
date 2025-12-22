#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*

Example 1:

Input: N=4, matrix=[[7263,3483,9154,62], [5944,8721,5154,9591], [9752,1696,6616,3170], [5287,7014,7885,2554]]

Output: 5287 9752 5944 7263 7014 1696 8721 3483 7885 6616 5154 9154 2554 3170 9591 62

Example 2:

Input: N=3, matrix=[[1,2,3], [4,5,6], [7,8,9]]

Output: 7 4 1 8 5 2 9 6 3

Example 3:

Input: N=2, matrix=[[5745,3299], [3381,5838]]

Output: 3381 5745 5838 3299

*/

// rotate matrix clock wise

class Solution
{
public:
    void rotate90Clockwise(vector<vector<int>> &matrix, int N)
    {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // reverse of code
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
