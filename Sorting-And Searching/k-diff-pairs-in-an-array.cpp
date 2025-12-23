#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/*

Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
|nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.


Example 1:

Input: nums = [3,1,4,1,5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:

Input: nums = [1,2,3,4,5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:

Input: nums = [1,3,1,5,4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).


Constraints:

1 <= nums.length <= 104
-107 <= nums[i] <= 107
0 <= k <= 107

*/

// Two Pointer->https://leetcode.com/problems/k-diff-pairs-in-an-array/submissions/1862623380/

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        set<pair<int, int>> ans;
        int i = 0, j = 1;
        while (j < nums.size())
        {
            int diff = nums[j] - nums[i];
            if (diff == k)
            {
                ans.insert({nums[i], nums[j]});
                ++i;
                ++j;
            }
            else if (diff > k)
            {
                i++;
            }
            else
            {
                j++;
            }
            if (i == j)
                j++;
        }
        return ans.size();
    }
};

/*

🧪 IMPORTANT MAIN 3 TEST CASES
✅ Test Case 1 (Duplicates – MOST IMPORTANT)
nums = [3,1,4,1,5]
k = 2
Output = 2
Pairs → (1,3), (3,5)


👉 (1,3) appears twice but counted once because of set

✅ Test Case 2 (k = 0 case)
nums = [1,1,1,1]
k = 0
Output = 1
Pair → (1,1)


👉 set avoids multiple (1,1) counts

✅ Test Case 3 (Mixed duplicates)
nums = [1,1,1,2,2,2]
k = 1
Output = 1
Pair → (1,2)


👉 Without set → wrong count

⏱️ Complexity

Time: O(n log n)

Space: O(n) (set)

*/

// binary search technique

class Solution
{
public:
    int bs(vector<int> &nums, int start, int x)
    {
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] == x)
            {
                return mid;
            }
            else if (x > nums[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return -1;
    }

    int findPairs(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        set<pair<int, int>> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (bs(nums, i + 1, nums[i] + k) != -1)
            {
                ans.insert({nums[i], nums[i] + k});
            }
        }
        return ans.size();
    }
};

/*

Algorithm (Binary Search Method):

Sort the array nums.

For every element nums[i], search nums[i] + k using binary search in the right part (i+1 to end).

If found, store the pair (nums[i], nums[i]+k) in a set to avoid duplicates.

Return the size of the set.

*/

// important note->  agar ka negative ho to approach

#include <set>
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        set<pair<int, int>> ans;
        k = abs(k);
        int i = 0, j = 1;

        while (i < nums.size() && j < nums.size())
        {
            int diff = nums[j] - nums[i];

            if (diff == k)
            {
                ans.insert({nums[i], nums[j]});
                i++;
                j++;
            }
            else if (diff > k)
            {
                i++;
            }
            else
            {
                j++;
            }

            if (i == j)
                j++;
        }
        return ans.size();
    }
};

/*

🧠 Yaad rakhne ka GOLDEN NOTE (abs(k) kyu lagaya)
👉 Reason (1 line)

Array sort karne ke baad nums[j] - nums[i] kabhi negative nahi hota,
isliye agar k negative ho to compare karne ke liye abs(k) lagana padta hai.

📌 Mini Example (dimag me chipak jaaye)
nums = [1,2,3,4,5]
k = -1


Sorted array me:

nums[j] - nums[i] = 1, 1, 1, 1   (kabhi -1 nahi aayega)


❌ 1 == -1 → kabhi true nahi
✅ abs(-1) = 1 → 1 == 1 → pairs milte hain

*/