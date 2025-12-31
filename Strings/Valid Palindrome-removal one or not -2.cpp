#include <iostream>
using namespace std;
/*

Given a string s, return true if the s can be palindrome after deleting at most one character from it.


Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false


*/

class Solution
{
public:
    bool checkPalindrome(string s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }

    bool validPalindrome(string s)
    {
        int i = 0;
        int j = s.length() - 1;

        while (i <= j)
        {
            // match
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                // no match
                bool caseOneAns = checkPalindrome(s, i, j - 1);
                bool caseTwoAns = checkPalindrome(s, i + 1, j);
                bool finalAns = caseOneAns || caseTwoAns;
                return finalAns;
            }
        }
        // agar aapne puri string travel kr li aur jaha tak aa gaye to iska matlb puri string me kahi per bhi nomatch nhi hua iska matlb 0 removal wala palindrome case tha ye
        return true;
    }
};