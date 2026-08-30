#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    /*
  int  solve(vector<int>&nums,int index){
       if(index>=nums.size()){
           return 0;
       }
       //include
       int include=nums[index]+solve(nums,index+2);
       //exclude
       int exclude=0+solve(nums,index+1);
       //final ans
       int finalAns=max(include,exclude);
       //return ans
       return finalAns;
    }
*/
    int DpSolution(vector<int> &nums, int index, vector<int> &dp)
    {
        if (index >= nums.size())
        {
            return 0;
        }
        if (dp[index] != -1)
        {
            return dp[index];
        }
        // include
        int include = nums[index] + DpSolution(nums, index + 2, dp);
        // exclude
        int exclude = 0 + DpSolution(nums, index + 1, dp);
        // final ans
        int finalAns = max(include, exclude);
        // return ans
        dp[index] = finalAns;
        return finalAns;
    }

    int rob(vector<int> &nums)
    {
        int index = 0;

        // int ans=solve(nums,index);
        // return  ans;
        int n = nums.size();
        vector<int> dp(n, -1);
        int dpAns = DpSolution(nums, index, dp);
        return dpAns;
    }
};


