#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int solveUsingDp(vector<vector<int>> &grid, int i, int j)
    {
        // base case
        if (i == 0 && j == 0)
        {
            return grid[i][j];
        }
        if (i < 0 || j < 0)
        {
            return INT_MAX;
        }
        int up = solveUsingDp(grid, i - 1, j);
        int left = solveUsingDp(grid, i, j - 1);
        if (up != INT_MAX)
        {
            up += grid[i][j];
        }
        if (left != INT_MAX)
        {
            left += grid[i][j];
        }
        return min(up, left);
    }

    int solveUsingDp(vector<vector<int>> grid, int i, int j, vector<vector<int>> &dp)
    {
        // base case
        if (i == 0 && j == 0)
        {
            return grid[i][j];
        }
        if (i < 0 || j < 0)
        {
            return INT_MAX;
        }
        // if ans exist return it
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int up = solveUsingDp(grid, i - 1, j, dp);
        int left = solveUsingDp(grid, i, j - 1, dp);
        if (up != INT_MAX)
        {
            up += grid[i][j];
        }
        if (left != INT_MAX)
        {
            left += grid[i][j];
        }
        int ans = min(up, left);
        return dp[i][j] = ans;
    }
    int solveUsingTabulation(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = grid[0][0];
        // First row
        for (int j = 1; j < n; j++)
        {
            dp[0][j] = grid[0][j] + dp[0][j - 1];
        }
        // First column
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                int up = dp[i - 1][j];
                int left = dp[i][j - 1];
                int ans = min(up, left) + grid[i][j];
                dp[i][j] = ans;
            }
        }
        return dp[m - 1][n - 1];
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        // pass row-1,colm-1;
        // int ans=solveUsingDp(grid,m-1,n-1);
        // create dp array
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // create a function and pass the dp array
        // memorization
        // int ans=solveUsingDp(grid,m-1,n-1,dp);
        //  return  ans;
        // solve using Tabulation
        int ans = solveUsingTabulation(grid);
        return ans;
    }
};
