#include <iostream>
#include <vector>
using namespace std;

/*

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

*/

class Solution
{
public:
    /*
        bool solve(vector<int>&nums,int index,int target){
         // base case handle
         if(target==0){
            return true;
         }
         if(index==nums.size()){
            return false;
         }
        if(target<0) return false;
         //1 case handle by me
         // target=target-nums[index];
          //recursive call
          bool includeAns=solve(nums,index+1,target-nums[index]);
          bool excludeAns=solve(nums,index+1,target);
          return includeAns|| excludeAns;

        }
      */
    int solveUsingMem(vector<int> &nums, int index, int target, vector<vector<int>> &dp)
    {
        // base case handle
        if (target == 0)
        {
            return true;
        }
        if (index == nums.size())
        {
            return false;
        }
        if (target < 0)
            return false;
        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }
        // 1 case handle by me
        //  target=target-nums[index];
        // recursive call
        bool includeAns = solveUsingMem(nums, index + 1, target - nums[index], dp);
        bool excludeAns = solveUsingMem(nums, index + 1, target, dp);
        int ans = includeAns || excludeAns;
        dp[index][target] = ans;
        return ans;
    }

    bool solveUsingTab(vector<int> &nums, int index, int target)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i][0] = 1;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            bool includeAns = 0;
            for (int j = 1; j <= target; j++)
            {
                if (j - nums[i] >= 0)
                {
                    includeAns = dp[i + 1][j - nums[i]];
                }
                bool excludeAns = dp[i + 1][j];
                int ans = includeAns || excludeAns;
                dp[i][j] = ans;
            }
        }
        return dp[0][target];
    }

    bool canPartition(vector<int> &nums)
    {
        int index = 0;
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        int target = sum / 2;
        if (sum % 2 != 0)
            return false;
        // bool ans=solve(nums,index,target);
        // return ans;
        // solveUsingMem
        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        // int memAns=solveUsingMem(nums,index,target,dp);
        // return memAns;
        // solve using tabulation
        int ansTab = solveUsingTab(nums, index, target);
        return ansTab;
    }
};
