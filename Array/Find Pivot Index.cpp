#include <iostream>
#include <vector>
using namespace std;

/*

Given an integer array nums, find the pivot index of this array.

The pivot index is defined as the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the right of the index.

If no such index exists, return -1. If there are multiple pivot indices, you should return the left-most pivot index.

Notes:
The array may contain negative numbers and be either large or small.
Example 1:

Input:

n=6 nums=[1,7,3,6,5,6]

Output:

3
Explanation:Left-sum (1 + 7 + 3) = 11 and right-sum (5 + 6) = 11 at index 3.

Example 2:

Input:

n=3 nums=[2,1,-1]

Output:

0
Explanation:Left-sum = 0 and right-sum (1 + –1) = 0, so index 0 is the pivot.

Example 3:

Input:

n=3 nums=[1,-1,0]

Output:

2
Explanation:Left-sum (1 + –1) = 0 and right-sum = 0 after index 2.

*/

class Solution
{
public:
    int bruteforce(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {

            int lsum = 0;
            int rsum = 0;

            // Left sum
            for (int j = 0; j < i; j++)
            {
                lsum += nums[j];
            }

            // Right sum
            for (int j = i + 1; j < n; j++)
            {
                rsum += nums[j];
            }

            // Compare
            if (lsum == rsum)
                return i;
        }

        return -1;
    }

    int pivotIndex(vector<int> &nums)
    {
        return bruteforce(nums);
    }
};

// uper bale ki time complexity o(n2) hai jo ki jaida time legi ab hum new code likhnge jisme time complexity o(n) hogi

class PivotIndex
{
public:
    int pivotIndex(vector<int> &arr)
    {
        int totalSum = 0;

        // Step 1: calculate total sum
        for (int x : arr)
            totalSum += x;

        int leftSum = 0;

        // Step 2: check pivot index
        for (int i = 0; i < arr.size(); i++)
        {
            int rightSum = totalSum - leftSum - arr[i];

            if (leftSum == rightSum)
                return i;

            leftSum += arr[i];
        }

        return -1;
    }
};

// iski time complexity o(n) hai
//  int rightSum = totalSum - leftSum - arr[i]; formula to find right sum
// isse formule se  humara right sum nikalne ka loop bach gaya jisse humari time compelxtiy kam ho gayi