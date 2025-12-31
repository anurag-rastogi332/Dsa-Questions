#include <iostream>
#include <string>
using namespace std;

/*

Examples:
Example 1:

Input: s = "paper", t = "title"
Output: true
Example 2:

Input: s = "ab", t = "aa"
Output: false
Example 1:

Input:

s = 'egg', t = 'add'

Output:

true
Explanation:Mapping 'e' to 'a' and 'g' to 'd' makes the strings isomorphic.

Example 2:

Input:

s = 'foo', t = 'bar'

Output:

false
Explanation:Character 'o' would have to map to both 'a' and 'r', which is not allowed.

Example 3:

Input:

s = 'paper', t = 'title'

Output:

true
Explanation:Mapping 'p' to 't', 'a' to 'i', 'e' to 'l', and 'r' to 'e' makes the strings isomorphic.

*/

class Solution
{
public:
    bool isIsomorphic(const string &s, const string &t)
    {
        if (s.size() != t.size())
            return false;
        int hash[256] = {
            0}; // mapping of each char of language 's1' to language 's2'
        bool isCharsMapped[256] = {
            0}; // stores if s2[i] char already mapped with s1[i]

        for (int i = 0; i < s.size(); i++)
        {
            if (hash[s[i]] == 0 && isCharsMapped[t[i]] == 0)
            {
                hash[s[i]] = t[i];
                isCharsMapped[t[i]] = true;
            }
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (hash[s[i]] != t[i])
            {
                return false;
            }
        }
        return true;
    }
};

// 1) Agar lengths different hain → isomorphic possible hi nahi → return false
// 2) hash[ch] = s ke char ka mapping t ke char se
// 3) isCharsMapped[ch] = batata hai t ka char pehle se kisi aur se mapped hai ya nahi
// 4) Pehle loop me mapping set karo (s[i] → t[i]) only jab dono unused hon
// 5) Dusre loop me verify karo ki har s[i] ka mapped char exactly t[i] hi ho
// 6) Agar kahin mismatch mile → return false, warna end me true
