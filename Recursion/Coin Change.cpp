#include <iostream>
#include <climits>
#include <vector>
using namespace std;

/*

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0

*/

class Solution
{
public:
    int solveUsingRecursion(vector<int> &coins, int amount)
    {
        // base case
        if (amount == 0)
        {
            return 0;
        }

        // isse amount ko create krne ke liye
        //  i will try each and every coin
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            if (coins[i] <= amount)
            {
                // valid case
                //  maine ek coin use kr liya
                int recursionAns = solveUsingRecursion(coins, amount - coins[i]);
                // recursion ka answer can be valid or invalid
                if (recursionAns != INT_MAX)
                {
                    // ek valid answer mila hai
                    //  it may or may not be a minimum number
                    mini = min(mini, 1 + recursionAns);
                }
            }
        }
        return mini;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int ans = solveUsingRecursion(coins, amount);
        if (ans == INT_MAX)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};
