

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*

Note:
Consider scenarios where the array is of size 2 or contains negative numbers as potential edge cases.
Example 1:

Input:

nums=[2,7,11,15] target=9

Output:

0, 1
Explanation:2 + 7 = 9, and their indices are 0 and 1

Example 2:

Input:

nums=[3,2,4] target=6

Output:

1, 2
Explanation:2 + 4 = 6, hence indices 1 and 2

Example 3:

Input:

nums=[3,3] target=6

Output:

0, 1
Explanation:3 + 3 = 6, so the pair is 0 and 1

*/

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    // Your logic will go here.
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        int first = nums[i];
        int second = nums[j];
        int sum = first + second;

        if (sum == target)
        {
          return {i, j};
        }
      }
    }

    return {};
  }
};

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
      int complement = target - nums[i];

      if (mp.count(complement))
      {
        return {mp[complement], i};
      }

      mp[nums[i]] = i;
    }

    return {};
  }
};