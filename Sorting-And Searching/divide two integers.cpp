#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// leetcode-29:-https://leetcode.com/problems/divide-two-integers/description/
/*

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.


Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0

*/

class Solution
{
public:
    long long int solve(long long int dividend, long long int divisor)
    {

        long long int s = 0;
        long long int e = dividend;
        long long int ans = -1;

        while (s <= e)
        {
            long long mid = s + ((e - s) >> 1);
            long long product = divisor * mid;

            if (product == dividend)
            {
                return mid;
            }
            else if (product > dividend)
            {
                e = mid - 1;
            }
            else
            {
                // store and compute logic
                ans = mid;
                s = mid + 1;
            }
        }
        return ans;
    }

    long long int divide(long long int dividend, long long int divisor)
    {

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        if (divisor == 0)
            return INT_MAX;

        long long int ans = solve(abs((long long int)dividend), abs((long long int)divisor));

        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
            return ans;

        else
        {
            return (0 - ans);
        }
        return 0;
    }
};