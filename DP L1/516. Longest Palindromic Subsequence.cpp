#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

/*

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".

*/

class Solution
{
public:
    // solve using tabulation method
    int solveUsingTab(string t1, string t2)
    {
        // create a 2d vector , and fill with the base case analysis
        int n = t1.size();
        int m = t2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (i > n || j > m)
                {
                    continue;
                }
                else
                {
                    if (t1[i] == t2[j])
                    {
                        int ans1 = 1 + dp[i + 1][j + 1];
                        dp[i][j] = ans1;
                    }
                    // baki ka mai recursion ko de dunga
                    else
                    {
                        int ans2 = max(dp[i + 1][j], dp[i][j + 1]);
                        dp[i][j] = ans2;
                    }
                }
            }
        }
        return dp[0][0];
    }

    int longestPalindromeSubseq(string s)
    {
        string first = s;
        reverse(s.begin(), s.end());
        string second = s;
        int ans = solveUsingTab(first, second);
        return ans;
    }
};