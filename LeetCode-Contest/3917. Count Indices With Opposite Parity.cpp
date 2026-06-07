#include <iostream>
#include <vector>
using namespace std;

/*

You are given an integer array nums of length n.

The score of an index i is defined as the number of indices j such that:

i < j < n, and
nums[i] and nums[j] have different parity (one is even and the other is odd).
Return an integer array answer of length n, where answer[i] is the score of index i.



Example 1:

Input: nums = [1,2,3,4]

Output: [2,1,1,0]

Explanation:

nums[0] = 1, which is odd. Thus, the indices j = 1 and j = 3 satisfy the conditions, so the score of index 0 is 2.
nums[1] = 2, which is even. Thus, the index j = 2 satisfies the conditions, so the score of index 1 is 1.
nums[2] = 3, which is odd. Thus, the index j = 3 satisfies the conditions, so the score of index 2 is 1.
nums[3] = 4, which is even. Thus, no index satisfies the conditions, so the score of index 3 is 0.
Thus, the answer = [2, 1, 1, 0].

Example 2:

Input: nums = [1]

Output: [0]

Explanation:

There is only one element in nums. Thus, the score of index 0 is 0.

*/

class Solution
{
public:
    bool checkEvenOdd(int num)
    {
        if ((num & 1) == 0)
        {
            return true;
        }
        return false;
    }

    int EvenAns(vector<int> &nums, int i)
    {
        int n = nums.size();
        int count = 0;
        for (int j = i + 1; j < n; j++)
        {
            if ((nums[j] & 1) == 1)
            {
                count++;
            }
        }
        return count;
    }

    int OddAns(vector<int> &nums, int i)
    {
        int n = nums.size();
        int count = 0;
        for (int k = i + 1; k < n; k++)
        {

            if ((nums[k] & 1) == 0)
            {
                count++;
            }
        }
        return count;
    }

    vector<int> countOppositeParity(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;

        if (n == 1)
        {
            ans.push_back(0);
            return ans;
        }

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            bool A = checkEvenOdd(num);
            if (i == n - 1)
            {
                ans.push_back(0);
                continue;
            }
            if (A)
            {
                int evenAns = EvenAns(nums, i);
                ans.push_back(evenAns);
            }

            else
            {
                int oddAns = OddAns(nums, i);
                ans.push_back(oddAns);
            }
        }
        return ans;
    }
};