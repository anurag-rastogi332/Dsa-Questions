#include <iostream>
#include <climits>
#include <vector>
using namespace std;

/*

Example 1:

Input:

Input: n = 5, arr = [3, 1, 4, 1, 5]

Output:

1
Explanation:The minimum element in [3, 1, 4, 1, 5] is 1.

Example 2:

Input:

Input: n = 4, arr = [10, 20, 5, 15]

Output:

5
Explanation:The minimum element in [10, 20, 5, 15] is 5.

Example 3:

Input:

Input: n = 6, arr = [5, 5, 5, 5, 5, 5]

Output:

5
Explanation:All elements are the same, so min is 5.

*/

void getMinElement(const vector<int> &arr, int n, int index, int &mini)
{
    // base case
    if (index >= n)
    {
        return;
    }

    // 1 case main solve karunga
    mini = min(mini, arr[index]);

    // recursive call
    getMinElement(arr, n, index + 1, mini);
}

int findMinRecursively(const vector<int> &arr, int n)
{
    int mini = INT_MAX;
    getMinElement(arr, n, 0, mini);
    return mini;
}