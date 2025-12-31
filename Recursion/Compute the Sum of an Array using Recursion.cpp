#include <iostream>
#include <vector>
using namespace std;

/*


Example
Input:

nums = [1, 2, 3, 4, 5]

Output:

15

Explanation: The sum of array elements is calculated as follows:

Start from index = 0, numb = 1
recursiveSum(nums, 1) = 2 + recursiveSum(nums, 2)
recursiveSum(nums, 2) = 3 + recursiveSum(nums, 3)
recursiveSum(nums, 3) = 4 + recursiveSum(nums, 4)
recursiveSum(nums, 4) = 5
recursiveSum(nums, 5) = 0 (base case)
When these are added together, the sum is 15.

Function Signature
cpp int recursiveSum(std::vector& nums, int index);

Example 1:

Input:

Input: n = 5, nums = [1, 2, 3, 4, 5]

Output:

15
Explanation:Sum of [1, 2, 3, 4, 5] is 1+2+3+4+5 = 15.

Example 2:

Input:

Input: n = 4, nums = [10, 20, 30, 40]

Output:

100
Explanation:Sum of [10, 20, 30, 40] is 10+20+30+40 = 100.

Example 3:

Input:

Input: n = 6, nums = [5, -5, 10, -10, 15, -15]

0
Explanation:Sum of [5, -5, 10, -10, 15, -15] is 0.

*/

int recursiveSum(vector<int> &nums, int index)
{
    if (nums.size() == index)
    {
        return 0;
    }
    return nums[index] + recursiveSum(nums, index + 1);
}