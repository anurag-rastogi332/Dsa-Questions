
/*
Example 1:
Input: arr = [-1, 0, 3, 5, 9, 12], target = 9
Output: 4
Explanation: The number 9 is located at index 4 in the array.
Example 2:
Input: arr = [-1, 0, 3, 5, 9, 12], target = 2
Output: -1
Explanation: The number 2 is not present in the array, thus the function returns -1.
Note:
Assume that all integers in the array arr are unique.
The algorithm should have a time complexity of O(log n).
Example 1:

Input:

Input: arr = [1, 2, 3, 4, 5, 6, 7, 8, 9], target = 5

Output:

4
Explanation:

Example 2:

Input:

Input: arr = [10, 20, 30, 40, 50, 60], target = 30

Output:

2
Explanation:

Example 3:

Input:

Input: arr = [1, 3, 5, 7, 9], target = 8

Output:

-1
Explanation:

*/

#include <bits/stdc++.h>
#include<vector>
using namespace std;

int binarySearch(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
