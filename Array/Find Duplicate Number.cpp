#include <iostream>
#include <vector>
using namespace std;

/*

You are given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one duplicate number in nums, return this duplicate number.

Note:
You must solve the problem without modifying the array nums and use only constant extra space.
Challenge:
Can you solve the problem in linear time, O(n)?

Example 1:

Input:

n=5 nums=[1,3,4,2,2]

Output:

2
Explanation:Among numbers 1‒4, the value 2 is repeated.

Example 2:

Input:

n=5 nums=[3,1,3,4,2]

Output:

3
Explanation:3 occurs at indices 0 and 2 → duplicate = 3.

Example 3:

Input:

n=5 nums=[1,1,2,3,4]

Output:

1
Explanation:The value 1 appears twice; all others are unique.

*/

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        while (nums[0] != nums[nums[0]])
        {
            swap(nums[0], nums[nums[0]]);
        }

        return nums[0];
    }
};
