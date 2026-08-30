#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /*
    int DpSolution(vector<int>&nums,int index,vector<int>&dp){
        if(index>=nums.size()){
           return 0;
       }
       if(dp[index]!=-1){
           return dp[index];
       }
       //include
       int include=nums[index]+DpSolution(nums,index+2,dp);
       //exclude
       int exclude=0+DpSolution(nums,index+1,dp);
       //final ans
       int finalAns=max(include,exclude);
       //return ans
       dp[index]=finalAns;
       return finalAns;
    }

    */

    // tabulation method /Bottom -Up Approach
    int solveUsingTabulation(vector<int> &nums)
    {
        // step1-> dp array create initialize
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        // step->2 analyse base case and fill dp array
        dp[n] = 0;
        // step->3 reverse the flow , loop ,copy paste

        for (int index = n - 1; index >= 0; index--)
        {
            int temp = 0;
            if (index + 2 <= n)
            {
                temp = dp[index + 2];
            }
            int include = nums[index] + temp;
            // exclude
            int exclude = 0 + dp[index + 1];
            // final ans
            dp[index] = max(include, exclude);
        }
        // step 4 return ans;
        return dp[0];
    }

    int rob(vector<int> &nums)
    {
        int index = 0;
        // int n=nums.size;
        // vector<int>dp(n,-1);
        int TabulationdpAns = solveUsingTabulation(nums);
        return TabulationdpAns;
    }
};