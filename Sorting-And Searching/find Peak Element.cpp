#include <iostream>
#include <vector>
using namespace std;

//     leet code-162 problem

/*

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

*/

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int s = 1, e = n - 1;

        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (nums[mid] < nums[mid + 1])
                s = mid + 1;

            else if (nums[mid] < nums[mid - 1])
                e = mid - 1;

            else
                return mid;
        }

        return -1;
    }
};