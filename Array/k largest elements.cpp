#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*  gfg-> https://www.geeksforgeeks.org/problems/k-largest-elements4206/1

Examples:

Input: arr[] = [12, 5, 787, 1, 23], k = 2
Output: [787, 23]
Explanation: 1st largest element in the array is 787 and second largest is 23.
Input: arr[] = [1, 23, 12, 9, 30, 2, 50], k = 3
Output: [50, 30, 23]
Explanation: Three Largest elements in the array are 50, 30 and 23.
Input: arr[] = [12, 23], k = 1
Output: [23]
Explanation: 1st Largest element in the array is 23.

*/

class Solution
{
public:
    vector<int> kLargest(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> ans;

        sort(arr.begin(), arr.end());

        for (int i = n - 1; i >= n - k; i--)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};