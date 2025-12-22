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
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int startingrow = 0, startingcolm = 0;
        int endingrow = n - 1, endingcolm = m - 1;

        vector<int> ans;

        while (startingrow <= endingrow && startingcolm <= endingcolm)
        {
            // startingrow print
            if (startingrow <= endingrow)
            {
                for (int col = startingcolm; col <= endingcolm; col++)
                {
                    ans.push_back(matrix[startingrow][col]);
                }
                startingrow++;
            }

            // endingcolm print
            if (startingcolm <= endingcolm)
            {
                for (int row = startingrow; row <= endingrow; row++)
                {
                    ans.push_back(matrix[row][endingcolm]);
                }
                endingcolm--;
            }

            // endingrow print
            if (startingrow <= endingrow)
            {
                for (int col = endingcolm; col >= startingcolm; col--)
                {
                    ans.push_back(matrix[endingrow][col]);
                }
                endingrow--;
            }

            // startingcolm print
            if (startingcolm <= endingcolm)
            {
                for (int row = endingrow; row >= startingrow; row--)
                {
                    ans.push_back(matrix[row][startingcolm]);
                }
                startingcolm++;
            }
        }
        return ans;
    }
};