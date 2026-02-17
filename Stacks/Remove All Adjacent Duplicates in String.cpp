#include <iostream>
#include <stack>
#include<algorithm>
using namespace std;

/*

Example:
Input:


s = "abbaca"
Output:


"ca"
Explanation:

In the first step, remove "bb", resulting in the string "aaca".
In the second step, "aa" is removed, resulting in "ca".
No further adjacent duplicates can be removed, so the final string is "ca".
Example 1:

Input:

s = 'abbaca'

Output:

ca
Explanation:Removing adjacent duplicates results in 'aaca' then 'ca'.

Example 2:

Input:

s = 'aabccb'

Explanation:Removing adjacent duplicates leads to an empty string.

Example 3:

Input:

s = 'abccba'

Explanation:After removing all adjacent duplicates, we get an empty string.


*/


class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            // agar stack empty hai -> push
            if (st.empty())
            {
                st.push(ch);
            }
            // agar top != current -> push
            else if (ch != st.top())
            {
                st.push(ch);
            }
            // agar top == current -> pop (remove duplicate pair)
            else
            {
                st.pop();
            }
        }

        // stack me answer ulta bana hoga, isliye reverse karna padega
        string ans = "";
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};