#include <iostream>
using namespace std;

// gfg link->https://www.geeksforgeeks.org/problems/given-two-strings-find-if-first-string-is-a-subsequence-of-second/1

/*

Examples:

Input: s1 = "AXY", s2 = "YADXCP"
Output: false
Explanation: s1 is not a subsequence of s2 as 'Y' appears before 'A'.
Input: s1 = "gksrek", s2 = "geeksforgeeks"
Output: true
Explanation: If we combine the bold character of "geeksforgeeks", it equals to s1. So s1 is a subsequence of s2.

*/

class Solution
{
public:
    bool isSubSeq(string &s1, string &s2)
    {
        int n = s1.size();
        int m = s2.size();
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }

        if (i == n)
        {
            return true;
        }
        return false;
    }
};

/*

/*
Algorithm:

1. Take two strings s1 and s2.
2. Initialize two pointers i=0 and j=0.
3. Traverse s2 while i < length(s1) and j < length(s2).
4. If s1[i] == s2[j], increment both i and j.
5. Otherwise increment j.
6. If i reaches length of s1, return true.
7. Otherwise return false.
*/

