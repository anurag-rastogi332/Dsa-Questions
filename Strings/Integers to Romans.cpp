#include <iostream>
#include <string>
using namespace std;

// leetcode->https://leetcode.com/problems/integer-to-roman/
/*

### Examples

Example 1:
Input: 123
Output: "CXXIII"

Example 2:
Input: 1994
Output: "MCMXCIV"

Remember to consider the subtractive combinations like IV (4), IX (9), XL (40), XC (90), CD (400), and CM (900) which are an essential part of this numeral system.

Example 1:

Input:

Input: num = 3

Output:

III
Explanation:The integer 3 is represented as 'III'.

Example 2:

Input:

Input: num = 58

Output:

LVIII
Explanation:58 is represented as 'LVIII' (50 + 5 + 3).

Example 3:

Input:

Input: num = 1994

Output:

MCMXCIV
Explanation:1994 is represented as 'MCMXCIV' (1000 + 900 + 90 + 4).

*/

class Solution
{
public:
    string intToRoman(int num)
    {
        string romanSymbols[] = {
            "M", "CM", "D", "CD", "C", "XC", "L",
            "XL", "X", "IX", "V", "IV", "I"};
        int values[] = {
            1000, 900, 500, 400, 100, 90, 50,
            40, 10, 9, 5, 4, 1};
        string ans = "";
        for (int i = 0; i < 13; i++)
        {
            while (num >= values[i])
            {
                ans += romanSymbols[i];
                num -= values[i];
            }
        }

        return ans;
    }
};