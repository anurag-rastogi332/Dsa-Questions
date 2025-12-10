

//  method-1

#include <iostream>
using namespace std;

/*

Example
Input

s = "anagram"

t = "nagaram"
Output

true
Explanation:

Both strings contain the letters a, g, m, n, r in the same frequencies. Thus, t is an anagram of s.

Additional Example
Input

s = "rat"

t = "car"
Output

false
Explanation:

The strings do not contain the same frequencies of letters. Therefore, t is not an anagram of s.

Example 1:

Input:

s = 'anagram', t = 'nagaram'

Output:

true
Explanation:'nagaram' is an anagram of 'anagram'.

Example 2:

Input:

s = 'rat', t = 'car'

Output:

false
Explanation:'car' is not an anagram of 'rat'.

Example 3:

Input:

s = 'hello', t = 'lloeh'

Output:

true
Explanation:'lloeh' is an anagram of 'hello'.



*/

class Solution
{
public:
    bool isAnagram(const string &s, const string &t)
    {
        int arr[1000] = {0};
        // for string s lets ad up counts
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            arr[ch]++;
        }

        // for string t, decrease the count
        for (int i = 0; i < t.length(); i++)
        {
            char ch = t[i];
            arr[ch]--;
        }
        // check all occurence are o only
        for (int i = 0; i < 1000; i++)
        {
            if (arr[i] != 0)
            {
                return false;
            }
        }
        // agar main yaha agya
        // iska mtlb kahin pr bhi 0 nhi mila array  me
        return true;
    }
};