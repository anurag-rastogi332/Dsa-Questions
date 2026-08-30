#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:

    // int solve(int n){
    //     if(n==0){
    //         return 0;
    //     }
    //     if(n==1 || n==2){
    //         return 1;
    //     }

    //     int ans=solve(n-1)+solve(n-2)+solve(n-3);
    //     return ans;

    // }

    int dpSolve(int n, vector<int> &dp)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1 || n == 2)
        {
            return 1;
        }
        // check
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int ans = dpSolve(n - 1, dp) + dpSolve(n - 2, dp) + dpSolve(n - 3, dp);
        dp[n] = ans;
        return dp[n];
    }

    int tribonacci(int n)
    {
        //  return solve(n);
        // using dp solve
        vector<int> dp(n + 1, -1);
        int ans = dpSolve(n, dp);
        return ans;
    }
};