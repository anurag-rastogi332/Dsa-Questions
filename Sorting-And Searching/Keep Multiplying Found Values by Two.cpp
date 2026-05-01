#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*

Example 1:

Input: nums = [5,3,6,1,12], original = 3
Output: 24
Explanation:
- 3 is found in nums. 3 is multiplied by 2 to obtain 6.
- 6 is found in nums. 6 is multiplied by 2 to obtain 12.
- 12 is found in nums. 12 is multiplied by 2 to obtain 24.
- 24 is not found in nums. Thus, 24 is returned.
Example 2:

Input: nums = [2,7,9], original = 4
Output: 4
Explanation:
- 4 is not found in nums. Thus, 4 is returned.


Constraints:

1 <= nums.length <= 1000
1 <= nums[i], original <= 1000

*/

class Solution
{
public:
    bool isExist(vector<int> &nums, int ans, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == ans)
            {
                return true;
            }
        }
        return false;
    }

    int findFinalValue(vector<int> &nums, int original)
    {
        int n = nums.size();
        long long int ans = original;
        bool exist = isExist(nums, ans, n);
        while (exist)
        {
            ans = ans * 2;
            exist = isExist(nums, ans, n);
        }
        return ans;
    }
};

// optinmal approach using set

class Solution
{
public:
    int findFinalValue(vector<int> &nums, int original)
    {
        unordered_set<int> s;

        for (int num : nums)
        {
            s.insert(num);
        }
        int ans = original;
        while (s.find(ans) != s.end())
        {
            ans = ans * 2;
        }
        return ans;
    }
};