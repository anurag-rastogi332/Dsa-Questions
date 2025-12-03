#include <iostream>
using namespace std;
#include <limits.h>

/*

Examples:
Example 1:
Input:
dividend = 10
divisor = 3
Output:
3
Explanation: Performing the division 10 / 3 results in 3.3333..., and after truncation towards zero, the result is 3.
Example 2:
Input:
dividend = 7
divisor = -3
Output:
-2
Explanation: Performing the division 7 / -3 results in -2.3333..., and after truncation towards zero, the result is -2.
Your task is to implement the function:


int findQuotient(int dividend, int divisor)
This function returns the integer quotient of dividing dividend by divisor with truncation towards zero.

Example 1:

Input:

Input: dividend = 10, divisor = 2

Output:

5
Explanation:10 divided by 2 gives quotient 5.

Example 2:

Input:

Input: dividend = 43, divisor = 5

Output:

8
Explanation:43 divided by 5 gives quotient 8 (ignoring remainder).

Example 3:

Input:

Input: dividend = -50, divisor = -5

Output:

10
Explanation:-50 divided by -5 gives quotient 10.

*/

#include <limits.h>

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

long long int findQuotient(int dividend, int divisor)
{
    // The user will implement this method
    if (divisor == 0)
    {
        return INT_MAX;
    }

    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    long long int ans =
        solve(abs((long long int)dividend), abs((long long int)divisor));

    if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
        return ans;

    else
    {
        return (0 - ans);
    }
    return 0;
}