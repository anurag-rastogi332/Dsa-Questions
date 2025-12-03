#include <iostream>
#include <vector>
using namespace std;

/*

Example
Input:


n = 5
arr = [3, 5, 10, 9, 11]
K = 10
Output:


2
Explanation: The element 10 can be found at index 2, satisfying the conditions of a nearly sorted array.

Additional Example
Input:


n = 4
arr = [1, 3, 4, 2]
K = 4
Output:


2
Explanation: The element 4 appears at index 2 in this nearly sorted array.

Example 1:

Input:

Input: n = 7, arr = [10, 3, 40, 20, 50, 80, 70], K = 40

Output:

2
Explanation:40 is found at index 2.

Example 2:

Input:

Input: n = 5, arr = [5, 10, 30, 20, 40], K = 20

Output:

3
Explanation:20 is found at index 3.

Example 3:

Input:

Input: n = 6, arr = [10, 20, 30, 40, 50, 60], K = 30

Output:

2
Explanation:30 is found at index 2.

*/

int findElementInNearlySortedArray(const vector<int> &arr, int target)
{
    // Implement the logic here
    // code here
    int n = arr.size();
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        // check mid for t target
        // as this is a almost sorted array
        // target can be found on 3 indexes -> mid,mid-1,mid+1

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid + 1] == target)
        {
            return mid + 1;
        }

        else if (arr[mid - 1] == target)
        {
            return mid - 1;
        }
        else if (target > arr[mid])
        {
            s = mid + 2;
        }
        else
        {
            e = mid - 2;
        }
    }

    return -1;

    return -1; // Placeholder return
}