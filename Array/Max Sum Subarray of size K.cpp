#include <iostream>
#include <vector>
using namespace std;

/*

Examples:

Input: arr[] = [100, 200, 300, 400], k = 2
Output: 700
Explanation: arr2 + arr3 = 700, which is maximum.
Input: arr[] = [1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4
Output: 39
Explanation: arr1 + arr2 + arr3 + arr4 = 39, which is maximum.
Input: arr[] = [100, 200, 300, 400], k = 1
Output: 400
Explanation: arr3 = 400, which is maximum.

*/

class Solution
{
public:
    int maxSubarraySum(vector<int> &arr, int k)
    {
        // use sliding window technique
        int n = arr.size();
        int windowSum = 0;

        for (int i = 0; i < k; i++)
        {
            windowSum += arr[i];
        }

        int maxSum = windowSum;

        for (int i = k; i < n; i++)
        {
            windowSum = windowSum + arr[i] - arr[i - k];
            maxSum = max(maxSum, windowSum);
        }

        return maxSum;
    }
};

// notes->

/*

🔹 What is Sliding Window?

Sliding Window is a technique used on arrays/strings to handle continuous (contiguous) elements efficiently.
Instead of recalculating again and again, we reuse previous results while moving the window step by step.

🔹 Why do we need it?

❌ Brute Force → same work repeated → slow
✅ Sliding Window → reuse sum/result → fast (O(n))

🔹 Types of Sliding Window (VERY IMPORTANT)
1️⃣ Fixed Size Sliding Window

When window size is already given (k fixed)

Examples:

Maximum sum of subarray of size k

Average of elements of size k

Count of subarrays of size k

Core Rule (Golden Formula):

new_window = old_window
             + new_element
             - removed_element


Steps:

Find sum of first k elements

Store it as answer

Slide window:

Add next element

Remove first element

Update answer

Time: O(n)
Space: O(1)

2️⃣ Variable Size Sliding Window

When size is NOT fixed, only condition is given

Examples:

Smallest subarray with sum ≥ X

Longest substring without repeating characters

Core Idea:

Expand window (right pointer ➡️)

If condition breaks → shrink window (left pointer ⬅️)

🔍 How to IDENTIFY Sliding Window Questions (EXAM TRICK)
✅ Use Sliding Window when you see:

✔ Array or String
✔ Continuous / Contiguous words
✔ Words like:

subarray

substring

window

consecutive

size k

maximum / minimum / longest / shortest

❌ Do NOT use Sliding Window when:

✖ Elements are NOT continuous
✖ Order doesn’t matter
✖ Question asks for pairs (→ Two Sum / Hashing)

*/