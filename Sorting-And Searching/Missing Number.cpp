

/*

Example 1:

Input:

n=3 nums=[3,0,1]

Output:

2
Explanation:The range should contain {0,1,2,3}. Only 2 is absent.

Example 2:

Input:

n=4 nums=[1,2,3,4]

Output:

0
Explanation:Numbers present are {1,2,3,4}; 0 is missing.

Example 3:

Input:

n=4 nums=[0,1,2,3]

Output:

4
Explanation:Expected range is {0,1,2,3,4}; 4 is not present.

*/

#include <iostream>
using namespace std;
#include <algorithm>
#include <algorithm>
#include <vector>
class Solution
{
public:
    int getMissingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        int ans = n; // kyunki agar koi bhi element missing ni hoga to last number missing hoga

        while (s <= e)
        {
            int mid = (s + e) / 2;

            if (mid == nums[mid])
            {
                // right
                s = mid + 1;
            }
            else
            {
                ans = mid;
                // left
                e = mid - 1;
            }
        };
        return ans;
    }

    int missingNumber(vector<int> &nums)
    {
        // first sort

        sort(nums.begin(), nums.end());
        int ans = getMissingNumber(nums);
        return ans;
    }
};