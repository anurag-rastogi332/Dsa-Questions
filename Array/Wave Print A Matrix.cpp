#include <iostream>
#include <vector>
using namespace std;

/*

Example 1:

Input:

m=3 n=3 matrix=[[1,2,3],[4,5,6],[7,8,9]]

Output:

1 4 7 8 5 2 3 6 9
Explanation:Wave order (col-wise): 1 4 7 ↓, then 8 5 2 ↑, then 3 6 9 ↓.

Example 2:

Input:

m=3 n=4 matrix=[[1,2,3,4],[5,6,7,8],[9,10,11,12]]

Output:

1 5 9 10 6 2 3 7 11 12 8 4
Explanation:Even columns top→bottom, odd columns bottom→top.

Example 3:

Input:

m=1 n=5 matrix=[[1,2,3,4,5]]

Output:

1 2 3 4 5
Explanation:Only one row, so wave is left-to-right.

*/

class Solution
{
public:
    vector<int> wavePrintMatrix(vector<vector<int>> &matrix, int m, int n)
    {
        vector<int> result;
        for (int j = 0; j < n; ++j)
        {
            if (j % 2 == 0)
            {
                for (int i = 0; i < m; ++i)
                {
                    result.push_back(matrix[i][j]);
                }
            }
            else
            {
                for (int i = m - 1; i >= 0; --i)
                {
                    result.push_back(matrix[i][j]);
                }
            }
        }
        return result;
    }
};