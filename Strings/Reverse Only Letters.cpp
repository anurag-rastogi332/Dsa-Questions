#include <iostream>
#include <string>
using namespace std;

/*

Example
Input:
s = "a-bC-dEf-ghIj"

Output:
"j-Ih-gfE-dCba"

Explanation
In the example above, letters a, b, C, d, E, f, g, h, I, and j are reversed to become j, I, h, g, f, E, d, C, b, and a, respectively. Meanwhile, the dashes remain in their original position.

Example 1:

Input:

Input: s = 'ab-cd'

Output:

dc-ba
Explanation:Only letters 'a', 'b', 'c', 'd' are reversed.

Example 2:

Input:

Input: s = 'a-bC-dEf-ghIj'

Output:

j-Ih-gfE-dCba
Explanation:Only letters are reversed; non-letter characters remain in place.

Example 3:

Input:

Input: s = 'Test1ng-Leet=code-Q!'

Output:

Qedo1ct-eeLg=ntse-T!
Explanation:Only letters are reversed; digits and symbols remain in place.

*/

class Solution
{
public:
    string reverseOnlyLetters(string &s)
    {
        int l = 0;
        int h = s.size() - 1;
        while (l < h)
        {
            if (((s[l] >= 'A' && s[l] <= 'Z') || (s[l] >= 'a' && s[l] <= 'z')) &&
                ((s[h] >= 'A' && s[h] <= 'Z') || (s[h] >= 'a' && s[h] <= 'z')))
            {
                swap(s[l], s[h]);
                l++;
                h--;
            }
            else if (!((s[l] >= 'A' && s[l] <= 'Z') ||
                       (s[l] >= 'a' && s[l] <= 'z')))
            {
                l++;
            }
            else
            {
                // s[h]-> non alpha
                h--;
            }
        }
        return s;
    }
};

// second solution both solution are best

class Solution
{
public:
    string reverseOnlyLetters(string &s)
    {
        int l = 0;
        int h = s.size() - 1;
        while (l < h)
        {
            if (isalpha(s[l]) && isalpha(s[h]))
            {
                swap(s[l], s[h]);
                l++;
                h--;
            }
            else if (!isalpha(s[l]))
            {
                l++;
            }
            else
            {
                // s[h]-> non alpha
                h--;
            }
        }
        return s;
    }
};