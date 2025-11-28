#include <iostream>
#include <vector>
using namespace std;

/*

Example 1:


Input: nums = [5,7,7,8,8,10], target = 8
Output: [3, 4]
Example 2:


Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1, -1]
Example 3:


Input: nums = [], target = 0
Output: [-1, -1]
Explanation
In Example 1, the target 8 appears from index 3 to 4. Thus, the output is [3, 4].
In Example 2, the target 6 is absent from the array, so the output is [-1, -1].
In Example 3, the array is empty, thus the target 0 is not found, resulting in [-1, -1].
Example 1:

Input:

Input: nums = [5,7,7,8,8,10], target = 8

Output:

[3, 4]
Explanation:

Example 2:

Input:

Input: nums = [5,7,7,8,8,10], target = 6

Output:

[-1, -1]
Explanation:

Example 3:

Input:

Input: nums = [], target = 0

Output:

[-1, -1]
Explanation:

*/

// important note:- aise questions jinme hum lage ki ye answer ho bhi sakta hai aur nhi bhi to us value ko store kr lo is technique ko hum store and compute kehte hai

class Solution
{
public:
    int LastOccurence(vector<int> &nums, int target)
    {

        int n = nums.size();
        int s = 0;
        int e = n - 1;
        int ans = -1;

        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (nums[mid] == target)
            {
                // store and compute
                ans = mid;
                // right
                s = mid + 1;
            }
            else if (target < nums[mid])
            {
                // left
                e = mid - 1;
            }
            else
            {
                // right
                s = mid + 1;
            }
        }
        return ans;
    }

    int firstOccurence(vector<int> &nums, int target)
    {

        int n = nums.size();
        int s = 0;
        int e = n - 1;
        int ans = -1;

        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (nums[mid] == target)
            {
                // store and compute
                ans = mid;
                // left
                e = mid - 1;
            }
            else if (target < nums[mid])
            {
                // left
                e = mid - 1;
            }
            else
            {
                // right
                s = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = firstOccurence(nums, target);
        int Last = LastOccurence(nums, target);
        vector<int> temp;
        temp.push_back(first);
        temp.push_back(Last);
        return temp;
    }
};