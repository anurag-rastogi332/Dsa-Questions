#include <iostream>
#include <vector>
using namespace std;

/*

Example 1:

Input: n=4, k=533, arr=[34,828,69,533]

Output: 3

Example 2:

Input: n=2, k=533, arr=[34, 828]

Output: -1

Example 3:

Input: n=4, k=851, arr=[996, 639, 914, 310]

Output: -1
*/

class Solution
{
public:
    int searchRecursive(vector<int> &arr, int k, int idx)
    {
        if (idx >= arr.size())
            return -1;
        if (arr[idx] == k)
            return idx;
        return searchRecursive(arr, k, idx + 1);
    }

    int findIndex(vector<int> &arr, int k) { return searchRecursive(arr, k, 0); }
};
