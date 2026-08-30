#include<iostream>
#include<vector>
using namespace std;

/*

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
 

*/

class Solution {
public:
    int solve(vector<int>&cost,int i,vector<int>&dp){
        // base case 
        if(i>=cost.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        // 1 case jo ki maine handle karunga
        int oneStep=cost[i]+solve(cost,i+1,dp);
        int twoStep=cost[i]+solve(cost,i+2,dp);

        // store dp
        return dp[i]=min(oneStep,twoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int i=0;
     //   int ans=min(solve(cost,0,),solve(cost,1,));
     //   return ans;
        int n=cost.size();
        vector<int>dp1(n+1,-1);
        int c1=solve(cost,0,dp1);
        vector<int>dp2(n+1,-1);
        int c2=solve(cost,1,dp2);
        return min(c1,c2);

    }
};

