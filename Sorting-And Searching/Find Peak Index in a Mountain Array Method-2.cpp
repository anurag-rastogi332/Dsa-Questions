// methid -2

#include <iostream>
#include <vector>
using namespace std;

/*

Example:


Input: arr = [0, 2, 5, 3, 1]
Output: 2
In this example, the peak element is 5, located at index 2.

Note:

The input is guaranteed to be a mountain array.
Example 1:

Input:

Input: arr = [0, 1, 0]

Output:

1
Explanation:

Example 2:

Input:

Input: arr = [1, 3, 5, 4, 2]

Output:

2
Explanation:

Example 3:

Input:

Input: arr = [0, 2, 4, 6, 5, 3, 1]

Output:

3
Explanation:

*/

int peakIndexInMountainArray(vector<int> &arr)
{
    // Your implementation here
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    int mid = (s + e) / 2;

    while (s < e)
    {
        if (arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = (s + e) / 2;
    }
    return mid;
}