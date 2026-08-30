#include <iostream>
#include <vector>
using namespace std;

/*

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3

*/


class Solution
{
public:
    /*
    int solve(vector<int>&nums,int i,int end){
        // base case
        if(i>end){
            return 0;
        }
        // 1 case mai solve karunga
        int include=nums[i]+solve(nums,i+2,end);
        // baki ka recursion me solve karenge
        int exclude=solve(nums,i+1,end);
        return max(include,exclude);
    }

    */
    int solve(vector<int> &nums, int i, int end, vector<int> &dp)
    {
        // base case
        if (i > end)
        {
            return 0;
        }

        if (dp[i] != -1)
        {
            return dp[i];
        }
        int include = nums[i] + solve(nums, i + 2, end, dp);
        int exclude = solve(nums, i + 1, end, dp);
        int ans = max(include, exclude);
        return dp[i] = max(include, exclude);
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        /*  int case1=solve(nums,0,n-2);
            int case2=solve(nums,1,n-1);
             return max(case1,case2);  */
        vector<int> dp1(n + 1, -1);
        int c1 = solve(nums, 0, n - 2, dp1);
        vector<int> dp2(n + 1, -1);
        int c2 = solve(nums, 1, n - 1, dp2);
        return max(c1, c2);
    }
};