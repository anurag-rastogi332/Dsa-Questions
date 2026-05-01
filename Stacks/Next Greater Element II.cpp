#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number.
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]


Constraints:

1 <= nums.length <= 104
-109 <= nums[i] <= 109

*/

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> s;

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (s.size() > 0 && nums[s.top()] <= nums[i % n])
            {
                s.pop();
            }

            ans[i % n] = s.empty() ? -1 : nums[s.top()];
            s.push(i % n);
        }

        return ans;
    }
};