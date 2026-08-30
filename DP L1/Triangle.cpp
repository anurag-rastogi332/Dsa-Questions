#include<iostream>
#include<vector>
using namespace std;


/*

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10


*/

class Solution
{
public:
    /*
        int solve(vector<vector<int>>&triangle,int row,int col ){
            if(row==triangle.size()-1){
                return triangle[row][col];
            }
            int down=triangle[row][col] +solve(triangle,row+1,col);
            int plus=triangle[row][col] +solve(triangle,row+1,col+1);
            return min(down,plus);
        }
    */

    int solveDp(vector<vector<int>> &triangle, int row, int col, vector<vector<int>> &dp)
    {
        if (row == triangle.size() - 1)
        {
            return triangle[row][col];
        }
        if (dp[row][col] != -1)
        {
            return dp[row][col];
        }
        int down = triangle[row][col] + solveDp(triangle, row + 1, col, dp);
        int plus = triangle[row][col] + solveDp(triangle, row + 1, col + 1, dp);
        int ans = min(down, plus);
        dp[row][col] = ans;
        return ans;
    }

    int solveTabulation(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // last row store
        for (int col = 0; col < n; col++)
        {
            dp[n - 1][col] = triangle[n - 1][col];
        }

        for (int row = n - 2; row >= 0; row--)
        {
            for (int col = 0; col <= row; col++)
            {
                int down = triangle[row][col] + dp[row + 1][col];
                int plus = triangle[row][col] + dp[row + 1][col + 1];
                int ans = min(down, plus);
                dp[row][col] = ans;
            }
        }
        return dp[0][0];
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        // return solve(triangle,0,0);
        //  int n=triangle.size();
        return solveTabulation(triangle);
    }
};
