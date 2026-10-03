#include<iostream>
#include<vector>
#include<climits>
using namespace std;

/*

Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation: 
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.

*/

class Solution {
public:
/*
    int solve(int i,int j,vector<vector<int>>&grid){
        //base case
        if(i==grid.size()-1){
            return grid[i][j];
        } 
        int ans=INT_MAX;
        for(int k=0;k<grid.size();k++){
            if(j!=k){
               int path = grid[i][j] + solve(i+1,k,grid);
                ans = min(ans,path);
            }
        }
       return ans;
    }
*/

   
    int solvedp(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        //base case
        if(i==grid.size()-1){
            return grid[i][j];
        } 
        //if answer already exist return it 
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int k=0;k<grid.size();k++){
            if(j!=k){
               int path = grid[i][j] + solvedp(i+1,k,grid,dp);
                ans = min(ans,path);
               
            }
        }
        dp[i][j]=ans;
       return ans;
    }
    
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        /*
        int n=grid.size();      
        int i=0;
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
         ans=min(ans,solve(i,j,grid));
        }
        return ans;
        */  
        //now convet it into dp memorization dp 
        int n=grid.size();
        // create 2d dp array
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int i=0;
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
         ans=min(ans,solvedp(i,j,grid,dp));
        }
        return ans;

    }
};