#include <iostream>
#include <vector>
using namespace std;

/*

Example 1:

Input: nums = [-2,-1,-1,1,2,3]
Output: 3
Explanation: There are 3 positive integers and 3 negative integers. The maximum count among them is 3.
Example 2:

Input: nums = [-3,-2,-1,0,0,1,2]
Output: 3
Explanation: There are 2 positive integers and 3 negative integers. The maximum count among them is 3.
Example 3:

Input: nums = [5,20,66,1314]
Output: 4
Explanation: There are 4 positive integers and 0 negative integers. The maximum count among them is 4.


Constraints:

1 <= nums.length <= 2000
-2000 <= nums[i] <= 2000
nums is sorted in a non-decreasing order.


Follow up: Can you solve the problem in O(log(n)) time complexity?

*/

class Solution
{
public:
    int firstOccurence(vector<int> &nums, int n)
    {
        int ans = n;
        int l = 0;
        int h = n - 1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (nums[mid] <= 0)
            {
                l = mid + 1;
            }
            else
            {
                ans = mid;
                h = mid - 1;
            }
        }
        return ans;
    }
    int lastOccurence(vector<int> &nums, int n)
    {
        int ans = -1;
        int l = 0;
        int h = n - 1;
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (nums[mid] >= 0)
            {
                h = mid - 1;
            }
            else
            {
                ans = mid;
                l = mid + 1;
            }
        }
        return ans;
    }

    int maximumCount(vector<int> &nums)
    {
        int n = nums.size();
        int first = firstOccurence(nums, n);
        int last = lastOccurence(nums, n);
        int positiveCount = 0;
        int negativeCount = 0;

        positiveCount = (n - first);
        negativeCount = last + 1;
        return max(positiveCount, negativeCount);
    }
};