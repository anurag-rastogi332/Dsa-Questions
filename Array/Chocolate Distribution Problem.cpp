#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/*

Input: arr = [3, 4, 1, 9, 56, 7, 9, 12], m = 5
Output: 6
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 9 - 3 = 6 by choosing m packets as [3, 4, 9, 7, 9].
Input: arr = [7, 3, 2, 4, 9, 12, 56], m = 3
Output: 2
Explanation: The minimum difference between maximum chocolates and minimum chocolates is 4 - 2 = 2 by choosing m packets as [3, 2, 4].
Input: arr = [3, 4, 1, 9, 56], m = 5
Output: 55
Explanation: With 5 packets for 5 students, each student will receive one packet, so the difference is 56 - 1 = 55.


*/

class Solution
{
public:
    int findMinDiff(vector<int> &a, int m)
    {
        sort(a.begin(), a.end());

        int ans = INT_MAX;
        int n = a.size();

        for (int i = m - 1; i < n; i++)
        {
            int d = a[i] - a[i - m + 1];
            ans = min(ans, d);
        }

        return ans;
    }
};