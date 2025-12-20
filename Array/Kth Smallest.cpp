
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// gfg->  https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

/*

Examples :

Input: arr[] = [10, 5, 4, 3, 48, 6, 2, 33, 53, 10], k = 4
Output: 5
Explanation: 4th smallest element in the given array is 5.
Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output: 7
Explanation: 3rd smallest element in the given array is 7.

*/

class Solution
{
public:
    int kthSmallest(vector<int> &arr, int k)
    {

        sort(arr.begin(), arr.end());

        return arr[k - 1];
    }
};