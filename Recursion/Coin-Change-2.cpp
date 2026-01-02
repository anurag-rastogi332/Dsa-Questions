#include <iostream>
#include <vector>
using namespace std;

/*

Example 1:

Input: amount = 5, coins = [1, 2, 5] Output: 4 Explanation: There are four ways to make up the amount: 5 = 5 5 = 2 + 2 + 1 5 = 2 + 1 + 1 + 1 5 = 1 + 1 + 1 + 1 + 1

Example 2:

Input: amount = 3, coins = [2] Output: 0 Explanation: The amount of 3 cannot be made with the given coins.

Example 3:

Input: amount = 10, coins = [10] Output: 1

Note:

You may assume that you have an infinite number of each kind of coin available.
Example 1:

Input:

Input: amount = 5, coins = [1, 2, 5]

Output:

4
Explanation:Ways to make 5: (5), (2+2+1), (2+1+1+1), (1+1+1+1+1)

Example 2:

Input:

Input: amount = 3, coins = [2]

0
Explanation:No way to make 3 using only coin 2.

Example 3:

Input:

Input: amount = 10, coins = [10]

Output:

1
Explanation:Only one way: (10)

*/

class Solution
{
public:
    int solve(int amount, int index, vector<int> &coins)
    {
        // base case
        if (amount == 0)
        {
            return 1;
        }
        if (index >= coins.size())
        {
            return 0;
        }
        // current coin ko include krke number of ways find karlo
        // main current coin ko tabhi include karunga jab bo amount se <=hoga
        int includeAns = 0;
        if (coins[index] <= amount)
        {
            includeAns = solve(amount - coins[index], index, coins);
        }
        // current coin ko exclude krke number of ways find karlo
        int excludeAns = solve(amount, index + 1, coins);
        // total ways nikal lo
        int total = includeAns + excludeAns;
        // return kardo
        return total;
    }

    int change(int amount, vector<int> &coins)
    {
        int index = 0;
        int ans = solve(amount, index, coins);
        return ans;
    }
};

// note-> is question ko krte hue leetcode pe tle aa gaya hai ise baad me hum dp se solve karenge achhe se
