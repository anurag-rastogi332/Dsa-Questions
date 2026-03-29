#include <bits/stdc++.h>
using namespace std;

/*

You are tasked with finding the index of a target value in an infinite-sized sorted array of integers. The array is sorted in ascending order, and as such, it does not explicitly define its size. To conquer the problem of infinity, you'll need to implement an Unbounded Search strategy. This involves identifying the range where the target exists and then applying a binary search within this range. If the target value is not present in the array, return -1. This challenge helps in understanding how to handle large or theoretically infinite datasets efficiently.

Example
Suppose you have an infinite-sized array that starts with:

[1, 2, 3, 4, 5, 6, ...]

If you search for the target value 4, your implemented function should return the index 3 since arrays are zero-based indexed.

Example 1:

Input:

nums = [1, 3, 5, 7, 9, 11, 13], target = 9

Output:

4
Explanation:Target 9 is found at index 4.

Example 2:

Input:

nums = [1, 2, 4, 8, 16, 32, 64], target = 5

Output:

-1
Explanation:Target 5 is not present in the array.

Example 3:

Input:

nums = [1, 2, 4, 8, 16, 32, 64], target = 64

Output:

6
Explanation:Target 64 is at index 6.

Constraints

• The array is sorted in ascending order.
• The get function returns a very large value (e.g., 10^9) if the index is out of bounds.

*/
class InfiniteArray
{
private:
    vector<int> arr;

public:
    InfiniteArray(vector<int> nums)
    {
        arr = nums;
    }

    int get(int index)
    {
        if (index >= arr.size())
            return INT_MAX;
        return arr[index];
    }
};

class Solution
{
public:
    int unboundedSearch(InfiniteArray &arr, int target)
    {

        if (arr.get(0) == target)
            return 0;

        int i = 1;

        while (arr.get(i) <= target)
        {
            i = i * 2;
        }

        int start = i / 2;
        int end = i;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (arr.get(mid) == target)
                return mid;

            else if (arr.get(mid) < target)
                start = mid + 1;

            else
                end = mid - 1;
        }

        return -1;
    }
};