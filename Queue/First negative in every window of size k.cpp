#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*

Note: If a window does not contain a negative integer, then return 0 for that window.

Examples:

Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
Output: [-8, 0, -6, -6]
Explanation:
Window [-8, 2] First negative integer is -8.
Window [2, 3] No negative integers, output is 0.
Window [3, -6] First negative integer is -6.
Window [-6, 10] First negative integer is -6.
Input: arr[] = [12, -1, -7, 8, -15, 30, 16, 28] , k = 3
Output: [-1, -1, -7, -15, -15, 0]
Explanation:
Window [12, -1, -7] First negative integer is -1.
Window [-1, -7, 8] First negative integer is -1.
Window [-7, 8, -15] First negative integer is -7.
Window [8, -15, 30] First negative integer is -15.
Window [-15, 30, 16] First negative integer is -15.
Window [30, 16, 28] No negative integers, output is 0.
Input: arr[] = [12, 1, 3, 5] , k = 3
Output: [0, 0]
Explanation:
Window [12, 1, 3] No negative integers, output is 0.
Window [1, 3, 5] No negative integers, output is 0.

Constraints:
1 <= arr.size() <= 106
-105 <= arr[i] <= 105
1 <= k <= arr.size()

*/

class Solution
{
public:
    vector<int> firstNegInt(vector<int> &arr, int k)
    {
        deque<int> dq;
        vector<int> ans;

        // process 1st window
        for (int index = 0; index < k; index++)
        {
            int element = arr[index];
            if (element < 0)
            {
                dq.push_back(index);
            }
        }

        if (dq.empty())
        {
            ans.push_back(0);
        }
        else
        {
            int index = dq.front();
            int element = arr[index];
            ans.push_back(element);
        }

        // remaining windows
        for (int i = k; i < arr.size(); i++)
        {
            // removal
            if (!dq.empty() && i - dq.front() >= k)
            {
                dq.pop_front();
            }

            // addition
            int element = arr[i];
            if (element < 0)
            {
                dq.push_back(i);
            }

            // answer
            if (dq.empty())
            {
                ans.push_back(0);
            }
            else
            {
                int index = dq.front();
                int element = arr[index];
                ans.push_back(element);
            }
        }

        return ans;
    }
};