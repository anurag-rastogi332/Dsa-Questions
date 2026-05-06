#include <iostream>
#include <unordered_map>
#include <deque>
using namespace std;

/*

Given a string s consisting of only lowercase alphabets, for each index i in the string (0 ≤ i < n), find the first non-repeating character in the prefix s[0..i]. If no such character exists, use '#'.

Examples:

Input: s = "aabc"
Output: a#bb
Explanation:
At i=0 ("a"): First non-repeating character is 'a'.
At i=1 ("aa"): No non-repeating character, so '#'.
At i=2 ("aab"): First non-repeating character is 'b'.
At i=3 ("aabc"): Non-repeating characters are 'b' and 'c'; 'b' appeared first, so 'b'.
Input: s = "bb"
Output: "b#"
Explanation:
At i=0 ("b"): First non-repeating character is 'b'.
At i=1 ("bb"): No non-repeating character, so '#'.
Constraints:
1 ≤ s.size() ≤ 105

*/

class Solution
{
public:
    string firstNonRepeating(string &s)
    {
        deque<char> dq;
        string ans;
        unordered_map<char, int> freq;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            // initial state maintain
            freq[ch]++;
            dq.push_back(ch);
            // lets find the answer now
            // logic->front k element k check krte raho jab tak answer na mile
            // agar answer nhi mila i.e. dq.empty() -> #store
            while (!dq.empty())
            {
                int frontElement = dq.front();
                // check whether front is the answer or not
                if (freq[frontElement] == 1)
                {
                    ans.push_back(frontElement);
                    break;
                }
                else
                {
                    // duplicate
                    dq.pop_front();
                }
            }
            // while loop se bahar hum do case me aa sakte hai
            // 1st case->answer store lrlia hoga ->dq empty nhi hogi
            // 2nd case-> dq empty hogyi -> # store krna padega
            if (dq.empty())
            {
                ans.push_back('#');
            }
        }
        return ans;
    }
};
