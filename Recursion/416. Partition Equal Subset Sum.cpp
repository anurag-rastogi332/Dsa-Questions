#include <iostream>
#include <vector>
using namespace std;

/*

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.



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
    bool solve(vector<int> &nums, int index, int target)
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
        // 1 case handle by me
        //  target=target-nums[index];
        // recursive call
        bool includeAns = solve(nums, index + 1, target - nums[index]);
        bool excludeAns = solve(nums, index + 1, target);
        return includeAns || excludeAns;
    }
    bool canPartition(vector<int> &nums)
    {
        int index = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        int target = sum / 2;
        if (sum % 2 != 0)
            return false;
        bool ans = solve(nums, index, target);
        return ans;
    }
};