#include <iostream>
using namespace std;

// is question ko samjhne ki try karo ye hard hai bahut aur complex bhi
/*

You are given an array of integers nums and an integer k. Your task is to find the k-th smallest element in the array.

Note that it is the k-th smallest element in the sorted order, not the k-th distinct element. This means if duplicate numbers are present in the array, they should be considered in their respective positions when determining the k-th smallest element.

For example, if the array is [1, 2, 2, 3] and k=3, the 3rd smallest element is 2.

Example 1: Input: nums = [3, 2, 1, 5, 6, 4], k = 2 Output: 2 Explanation: If the array were sorted in non-decreasing order, it would be [1, 2, 3, 4, 5, 6]. The 2nd smallest element in this sorted list is 2.

Example 2: Input: nums = [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4 Output: 3 Explanation: If the array were sorted, it would be [1, 2, 2, 3, 3, 4, 5, 5, 6]. The 4th smallest element is 3.

Example 3: Input: nums = [7, 6, 5, 4, 3, 2, 1], k = 5 Output: 3 Explanation: If the array were sorted, it would be [1, 2, 3, 4, 5, 6, 7]. The 5th smallest element is 3.

Your solution should aim for an efficient time complexity, ideally better than O(N log N) if possible, for the general case.

Example 1:

Input:

nums = [7, 3, 9, 1, 5], k = 3

Output:

5
Explanation:When sorted, the array is [1, 3, 5, 7, 9]. The 3rd smallest element is 5.

Example 2:

Input:

nums = [7, 3, 9, 1, 5], k = 3

Output:

5
Explanation:When sorted, the array becomes [1, 3, 5, 7, 9]. The 3rd smallest is 5.

Example 3:

Input:

nums = [95, 20, 133, -49, 69, 125, 53, 142, 146, -16, 82], k = 4

Output:

53
Explanation:Sorted order is used to determine the k-th smallest element.

Constraints

1 <= k <= nums.length
1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int partition(vector<int> &nums, int low, int high)
    {
        int pivot = nums[high];
        int i = low;

        for (int j = low; j < high; j++)
        {
            if (nums[j] <= pivot)
            {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        swap(nums[i], nums[high]);
        return i;
    }

    int quickSelect(vector<int> &nums, int low, int high, int k)
    {
        if (low <= high)
        {
            int p = partition(nums, low, high);

            if (p == k)
            {
                return nums[p];
            }
            else if (p > k)
            {
                return quickSelect(nums, low, p - 1, k);
            }
            else
            {
                return quickSelect(nums, p + 1, high, k);
            }
        }

        return -1;
    }

    int findKthSmallest(vector<int> &nums, int k)
    {
        return quickSelect(nums, 0, nums.size() - 1, k - 1);
    }
};

// 2nd

#include <vector>
#include <random>
#include <algorithm>

class Solution
{
private:
    static std::mt19937 gen;

    int partition(std::vector<int> &nums, int low, int high)
    {
        int pivot = nums[high];
        int i = low - 1;

        for (int j = low; j < high; ++j)
        {
            if (nums[j] <= pivot)
            {
                i++;
                std::swap(nums[i], nums[j]);
            }
        }
        std::swap(nums[i + 1], nums[high]);
        return i + 1;
    }

    int randomPartition(std::vector<int> &nums, int low, int high)
    {
        std::uniform_int_distribution<> distrib(low, high);
        int pivot_index = distrib(gen);
        std::swap(nums[pivot_index], nums[high]);
        return partition(nums, low, high);
    }

    int quickselect(std::vector<int> &nums, int low, int high, int k_index)
    {
        if (low == high)
        {
            return nums[low];
        }

        int pivot_pos = randomPartition(nums, low, high);

        if (pivot_pos == k_index)
        {
            return nums[pivot_pos];
        }
        else if (k_index < pivot_pos)
        {
            return quickselect(nums, low, pivot_pos - 1, k_index);
        }
        else
        {
            return quickselect(nums, pivot_pos + 1, high, k_index);
        }
    }

public:
    int findKthSmallest(std::vector<int> &nums, int k)
    {
        if (nums.empty())
        {
            return -1;
        }
        return quickselect(nums, 0, nums.size() - 1, k - 1);
    }
};

// Define random number generator
std::mt19937 Solution::gen{std::random_device{}()};