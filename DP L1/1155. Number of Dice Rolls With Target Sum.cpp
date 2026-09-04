#include <iostream>
#include <vector>
using namespace std;


/*

Example 1:

Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.
Example 2:

Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
Example 3:

Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.

*/

class Solution
{
public:
    long long int mod = 1000000007;
    int solveUsingRec(int n, int k, int target)
    {
        // base case
        if (n < 0 || target == 0)
        {
            return 0;
        }
        if (n == 0 && target == 0)
        {
            return 1;
        }
        if (n == 0 && target != 0)
        {
            return 0;
        }
        if (n != 0 && target == 0)
        {
            return 0;
        }
        int ans = 0;
        for (int val = 1; val <= k; val++)
        {
            ans = ans + solveUsingRec(n - 1, k, target - val);
        }
        return ans;
    }

    // 2d DP
    // Rec + Mem
    int solveUsingMem(int n, int k, int target, vector<vector<long long int>> &dp)
    {
        // base case
        if (n < 0 || target < 0)
        {
            return 0;
        }
        if (n == 0 && target == 0)
        {
            return 1;
        }
        if (n == 0 && target != 0)
        {
            return 0;
        }
        if (n != 0 && target == 0)
        {
            return 0;
        }
        if (dp[n][target] != -1)
        {
            return dp[n][target];
        }

        long long int ans = 0;
        for (int val = 1; val <= k; val++)
        {
            ans = (ans % mod + solveUsingMem(n - 1, k, target - val, dp) % mod) % mod;
        }
        dp[n][target] = ans;
        return ans;
    }

    int numRollsToTarget(int n, int k, int target)
    {
        // int ans=solveUsingRec(n,k,target);
        // return ans;
        // 2d dp
        // parameter changes n,target
        vector<vector<long long int>> dp(n + 1, vector<long long int>(target + 1, -1));
        // Memoization
        int dpAns = solveUsingMem(n, k, target, dp);
        return dpAns;
    };
};