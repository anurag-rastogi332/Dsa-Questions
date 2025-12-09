#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23

*/

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = end;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            long long totalTime = 0;

            for (int i = 0; i < piles.size(); i++)
            {
                totalTime += (piles[i] + mid - 1) / mid;
            }

            if (totalTime <= h)
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }
};
