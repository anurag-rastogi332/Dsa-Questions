#include <iostream>
using namespace std;

/*

Example:
Input:
base = 2, exponent = 3

Output:
8

Explanation:

Start with base = 2 and exponent = 3.
Calculate 2^3: 2 * 2 * 2 = 8.
Return 8.
Note:
When exponent is 0, any base other than 0 should return 1.
When base is 0 and exponent is 0, consider the result as 1 (by convention in this problem).
Example 1:

Input:

Input: base = 2, exponent = 0

Output:

1
Explanation:Any number raised to power 0 is 1.

Example 2:

Input:

Input: base = 2, exponent = 1

Output:

2
Explanation:2^1 = 2.

Example 3:

Input:

Input: base = 2, exponent = 3

Output:

8
Explanation:2^3 = 2 × 2 × 2 = 8.

*/

int powerRecursive(int base, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }
    return base * powerRecursive(base, exponent - 1);
}