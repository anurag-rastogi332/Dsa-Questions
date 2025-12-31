#include <bits/stdc++.h>
using namespace std;

/*

Example 1:


Input: s = "a"
Output: ["", "a"]
Example 2:


Input: s = "ab"
Output: ["", "a", "b", "ab"]
Example 3:


Input: s = "abc"
Output: ["", "a", "b", "c", "ab", "ac", "bc", "abc"]
(The order of subsequences in the output list may vary.)

Example 4:


Input: s = ""
Output: [""]
Example 1:

Input: s = abc

Output: [, a, ab, abc, ac, b, bc, c]

Explaintation: This test case covers a standard scenario with distinct characters. All 2^3 = 8 subsequences are generated and returned in lexicographical order.

Example 2:

Input: s = a

Output: [, a]

Explaintation: This is a basic test case for a single-character string. It should produce the empty string and the character itself as subsequences. The order in the output list is lexicographical due to the use of std::set for uniqueness.

Example 3:

Input: s =

Output: []

Explaintation: Tests the edge case of an empty input string. The only subsequence is the empty string itself, represented as an empty list.

*/

class Solution
{
public:
    void solve(string s, int index, string output, vector<string> &ans)
    {
        // base case
        if (index >= s.length())
        {
            // 2 kaam ->rukhna jab h,subsequence ready hota hai is case pr
            ans.push_back(output);
            return;
        }
        // 1 case main solve kr deta hu
        // ek character ko pakad ke include ans exlude krdeta hu
        // baki recursion sambhal lega
        char ch = s[index];
        // include
        output.push_back(ch);
        solve(s, index + 1, output, ans);
        // backtrack
        output.pop_back();
        // exclude
        solve(s, index + 1, output, ans);
    }

    std::vector<std::string> generateAllSubsequences(std::string s)
    {
        vector<string> ans;
        int index = 0;
        string output = "";
        solve(s, index, output, ans);
        return ans;
    }
};