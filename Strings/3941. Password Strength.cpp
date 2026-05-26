#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/*

You are given a string password.

The strength of the password is calculated based on the following rules:

1 point for each distinct lowercase letter ('a' to 'z').
2 points for each distinct uppercase letter ('A' to 'Z').
3 points for each distinct digit ('0' to '9').
5 points for each distinct special character from the set "!@#$".
Each character contributes at most once, even if it appears multiple times.

Return an integer denoting the strength of the password.



Example 1:

Input: password = "aA1!"

Output: 11

Explanation:

The distinct characters are 'a', 'A', '1' and '!'.
Thus, the strength = 1 + 2 + 3 + 5 = 11.
Example 2:

Input: password = "bbB11#"

Output: 11

Explanation:

The distinct characters are 'b', 'B', '1' and '#'.
Thus, the strength = 1 + 2 + 3 + 5 = 11.​​​​​​​


*/

class Solution
{
public:
    int passwordStrength(string password)
    {
        int strength = 0;
        unordered_set<char> st;
        for (auto ch : password)
        {
            if (st.find(ch) == st.end())
            {
                st.insert(ch);
            }
        }
        for (auto ch : st)
        {
            if (ch >= 'a' && ch <= 'z')
            {
                strength += 1;
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                strength += 2;
            }
            else if (ch >= '0' && ch <= '9')
            {
                strength += 3;
            }
            else
            {
                strength += 5;
            }
        }
        return strength;
    }
};

class Solution
{
public:
    int passwordStrength(string password)
    {
        vector<bool> seen(128, false);
        int strength = 0;
        for (auto ch : password)
        {
            if (seen[ch])
            {
                continue;
            }
            seen[ch] = true;
            if (ch >= 'a' && ch <= 'z')
            {
                strength += 1;
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                strength += 2;
            }

            else if (ch >= '0' && ch <= '9')
            {
                strength += 3;
            }

            else
            {
                strength += 5;
            }
        }

        return strength;
    }
};