#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.



Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"

*/

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int i = num1.size() - 1;
        int j = num2.length() - 1;
        int carry = 0;
        string ans;

        while (i >= 0 || j >= 0 || carry > 0)
        {
            int csum = 0;

            if (i >= 0)
            {
                // num1 has digits left
                csum += num1[i] - '0';
                i--;
            }

            if (j >= 0)
            {
                // num2 has digits left
                csum += num2[j] - '0';
                j--;
            }

            csum += carry;

            int lastDigit = csum % 10;
            char lastDigitChar = lastDigit + '0';
            ans.push_back(lastDigitChar);

            carry = csum / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};