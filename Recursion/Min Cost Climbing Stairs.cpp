#include<iostream>
#include<vector>
using namespace std;

/*

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.


*/

class Solution
{
public:
    int solve(vector<int> &cost, int i)
    {
        // base case
        if (i >= cost.size())
        {
            return 0;
        }
        // 1 case jo ki maine handle karunga

        int include = cost[i] + solve(cost, i + 1);
        int exclude = cost[i] + solve(cost, i + 2);

        // recursive call kaun
        return min(include, exclude);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        int i = 0;
        int ans = min(solve(cost, 0), solve(cost, 1));
        return ans;
    }
};
