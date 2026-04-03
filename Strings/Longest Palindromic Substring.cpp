#include <iostream>
#include <string>
using namespace std;

/*

Given a string s, return the longest palindromic substring in s.



Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"

*/

class Solution
{
public:
    string checkPalindrome(string s, int i, int j)
    {
        while (i >= 0 && j < s.length() && s[i] == s[j])
        {
            i--;
            j++;
        }

        return s.substr(i + 1, j - i - 1);
    }
    string longestPalindrome(string s)
    {
        string ans = "";

        for (int centre = 0; centre < s.length(); centre++)
        {

            int i = centre;
            int j = centre;
            string odd = checkPalindrome(s, i, j);

            i = centre;
            j = centre + 1;
            string even = checkPalindrome(s, i, j);

            if (odd.length() > ans.length())
            {
                ans = odd;
            }

            if (even.length() > ans.length())
            {
                ans = even;
            }
        }

        return ans;
    }
};