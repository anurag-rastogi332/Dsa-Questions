#include<iostream>
#include<vector>
using namespace std;

/*

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

*/

class Solution
{
public:
    /*
        int solve(int n) {

            if(n < 0) {
                return 0;
            }
            if(n == 0) {
                return 1;
            }
            int oneStep = solve(n - 1);
            int twoStep = solve(n - 2);
            return oneStep + twoStep;
        }
    */

    int solveDp(int n, vector<int> &dp)
    {
        if (n < 0)
        {
            return 0;
        }
        if (n == 0)
        {
            return 1;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int oneStep = solveDp(n - 1, dp);
        int twoStep = solveDp(n - 2, dp);
        dp[n] = oneStep + twoStep;
        return dp[n];
    }

    int climbStairs(int n)
    {
        // return solve(n);
        vector<int> dp(n + 1, -1);
        return solveDp(n, dp);
    }
};