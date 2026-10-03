#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
/*
    int solve(int m,int n,int i,int j){
        // base case 
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i>m || j>n){
            return 0;
        }

        int down=solve(m,n,i+1,j);
        int right=solve(m,n,i,j+1);
        return down+right;
    }
    */

    int solveMem(int m,int n,int i,int j,vector<vector<int>>&dp){
      // base case 
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i>=m || j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int down=solveMem(m,n,i+1,j,dp);
        int right=solveMem(m,n,i,j+1,dp);
        return dp[i][j]=down+right;
    }
    int uniquePaths(int m, int n) {
       // int ans=solve(m,n,0,0);
       //    return ans;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int dpAns=solveMem(m,n,0,0,dp);
        return dpAns;
      
    }
};