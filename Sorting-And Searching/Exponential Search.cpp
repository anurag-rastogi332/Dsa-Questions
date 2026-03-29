#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*

In this problem, you are tasked with implementing the Exponential Search algorithm to find the index of a given target in a sorted array of integers, nums. Exponential Search is particularly useful for unbounded or very large arrays. It works by progressively doubling the search range until it either finds the element or exceeds the search space.

Given a sorted array nums and an integer target, your goal is to find the position (index) of the target within the array. If the target is not present, return -1.

Example:

Input: nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], target = 5
Output: 4
Explanation: The target 5 is found at index 4 in the array.
Exponential Search combines the benefits of Binary Search while being more efficient in identifying the section of an array where the target might exist. Begin by searching for the target exponentially by doubling the range, and once you narrow down the area where the target could be, use Binary Search to find the exact index.

Example 1:

Input:

nums = [1, 3, 5, 7, 9, 11, 13, 15], target = 7

Output:

3
Explanation:Target 7 is found at index 3.

Example 2:

Input:

nums = [2, 4, 6, 8, 10, 12], target = 5

Output:

-1
Explanation:Target 5 is not in the array.

Example 3:

Input:

nums = [1, 2, 3, 4, 5], target = 1

Output:

0
Explanation:Target 1 is at index 0.

Constraints

• 1 ≤ nums.length ≤ 10^5
• -10^9 ≤ nums[i], target ≤ 10^9
• nums is sorted in ascending order.


*/

class Solution
{
public:
    int searchBinary(vector<int> &nums, int target, int start, int end)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target)
                return mid;

            else if (nums[mid] < target)
                start = mid + 1;

            else
                end = mid - 1;
        }
        return -1;
    }

    int exponentialSearch(vector<int> &nums, int target)
    {
        int n = nums.size();

        if (nums[0] == target)
            return 0;

        int i = 1;

        while (i < n && nums[i] <= target)
        {
            i = i * 2;
        }

        int start = i / 2;
        int end = min(i, n - 1);

        return searchBinary(nums, target, start, end);
    }
};