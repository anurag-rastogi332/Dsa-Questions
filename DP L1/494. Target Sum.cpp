#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:

    int solve(vector<int>& nums, int i, int sum, int target) {     
        if (i == nums.size()) {
            return sum == target ? 1 : 0;
        }
        int plus = solve(nums, i + 1, sum + nums[i], target);
        int minus = solve(nums, i + 1, sum - nums[i], target);

      return plus+minus;
    }
    
    int solveMem(vector<int>&nums,int i,int sum,int target,vector<vector<int>>&dp, int offset){
                if (i == nums.size()) {
            return sum == target ? 1 : 0;
        }
        int col = sum + offset;
        if(dp[i][col]!=-1){
            return dp[i][col];
        }
        int plus = solveMem(nums, i + 1, sum + nums[i], target,dp, offset);
        int minus = solveMem(nums, i + 1, sum - nums[i], target,dp, offset);

      return dp[i][col]= plus+minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        //return solve(nums, 0, 0, target);
        //Mem
        int total=0;
        for(auto x:nums){
            total+=x;
        }
        int offset = total;
        vector<vector<int>>dp(nums.size()+1,vector<int>(2 * total + 1,-1));
        int ansMem=solveMem(nums,0,0,target,dp,offset);
        return ansMem;
    }
};
