#include <iostream>
#include <vector>
using namespace std;

/*

In this problem, you are tasked with determining how much money you can rob from a line of houses without tripping the security systems. Each house has a certain amount of money, represented as a non-negative integer in an array nums. The catch is that robbing two directly adjacent houses will trigger the alarm, so you need to strategically choose which houses to rob to maximize your total haul for the night.

Example 1:

Input:

nums=[1,2,3,1]

Output:

4
Explanation:Rob houses 1 and 3 (money = 1 + 3 = 4) to get maximum amount.

Example 2:

Input:

nums=[2,7,9,3,1]

Output:

12
Explanation:Rob houses 1, 3, and 5 (money = 2 + 9 + 1 = 12) for maximum amount.

Example 3:

Input:

nums=[2,1,1,2]

Output:

4
Explanation:Rob houses 1 and 4 (money = 2 + 2 = 4) for maximum amount.

*/

class Solution
{
public:
    int solve(vector<int> &nums, int index)
    {
        // base case
        if (index >= nums.size())
        {
            return 0;
        }
        // include
        int includeAns = nums[index] + solve(nums, index + 2);
        // exclude
        int excludeAns = 0 + solve(nums, index + 1);
        int finalAns = max(includeAns, excludeAns);
        return finalAns;
    }

    int rob(vector<int> &nums)
    {
        int index = 0;
        int ans = solve(nums, index);
        return ans;
    }
};