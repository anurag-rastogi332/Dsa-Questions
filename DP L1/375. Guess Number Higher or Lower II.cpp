#include<iostream>
#include<vector>
#include<climits>
using namespace std;


class Solution {
public:
/*
    int solveUsingRecursion(int start, int end) {     
        if (start >= end) {
            return 0;
        }
        int ans = INT_MAX;
        for (int i = start; i <= end; i++) {
            int cost = i + max(
                solveUsingRecursion(start, i - 1),
                solveUsingRecursion(i + 1, end)
            );
            ans = min(ans, cost);
        }
        return ans;
    }
*/
    int solveMem(int start,int end,vector<vector<int>>&dp){
           if (start >= end) {
            return 0;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        int ans = INT_MAX;
        for (int i = start; i <= end; i++) {
            int cost = i + max(
                solveMem(start, i - 1,dp),
                solveMem(i + 1, end,dp)
            );
            ans = min(ans, cost);
            dp[start][end]=ans;
        }
        return dp[start][end];
    }
    int getMoneyAmount(int n) {
        // int ans = solveUsingRecursion(1, n);
        // return ans;
        //sovle using mem
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int memAns=solveMem(1,n,dp);
        return memAns;
    }
};
