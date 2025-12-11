#include <iostream>
using namespace std;

/*

Example 1:

Input: s = "abbaca"
Output: "ca"
Explanation:
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
Example 2:

Input: s = "azxxzy"
Output: "ay"

*/

class Solution
{
public:
    string removeDuplicates(string s)
    {
        string ans = "";

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            // 2 option
            // 1) insert kardo ->ch and rightmost different hoga or ans empty hoga
            if (ans.empty())
            {
                ans.push_back(ch);
            }
            else if (ch != ans.back())
            {
                ans.push_back(ch);
            }
            else
            {
                // ch and rightmost character in ans is same
                // remove the rightmost character
                ans.pop_back();
            }
            // donot insert and remove rightmost from and-ch and rightmost hoga
        }
        return ans;
    }
};