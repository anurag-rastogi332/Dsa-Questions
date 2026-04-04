#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*

Example 1:

Input: chars = ["a","a","b","b","c","c","c"]
Output: 6
Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
Example 2:

Input: chars = ["a"]
Output: 1
Explanation: The only group is "a", which remains uncompressed since it's a single character.
Example 3:

Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
Output: 4
Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".

*/

class Solution
{
public:
    int compress(vector<char> &s)
    {
        int index = 0;
        int count = 1;
        char prev = s[0];
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == prev)
            {
                count++;
            }
            else
            {
                s[index++] = prev;
                if (count > 1)
                {
                    int start = index;
                    while (count)
                    {
                        s[index++] = (count % 10) + '0';
                        count /= 10;
                    }
                    reverse(s.begin() + start, s.begin() + index);
                }
                prev = s[i];
                count = 1;
            }
        }
        s[index++] = prev;
        if (count > 1)
        {
            int start = index;
            while (count)
            {
                s[index++] = (count % 10) + '0';
                count /= 10;
            }
            reverse(s.begin() + start, s.begin() + index);
        }
        return index;
    }
};