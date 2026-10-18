#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*

Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.



Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0


*/

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int s = 0;
        int e = 0;
        int sum = 0;
        int len = INT_MAX;
        while (e < nums.size())
        {
            sum = sum + nums[e];
            // ho sakta hai ye sum less than ho ya greater than = ho
            while (sum >= target)
            {
                // minimise krna hai
                //  sabse pehle humare pass ek valid answer hai to isko store kr lete hain
                len = min(len, e - s + 1);
                // minimise krna hai
                // sum decrease hoga start wale number se
                sum = sum - nums[s];
                s++;
            }
            // agar mai yaha tak aa gaya to iska mtlb hai ki
            //  sum <target ho gaya hoga
            //  tab mere ko increate krna hai window ko
            // expand
            e++;
        }
        if (len == INT_MAX)
        {
            return 0;
        }
        else
        {
            return len;
        }
    }
};