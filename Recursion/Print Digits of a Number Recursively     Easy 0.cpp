#include<iostream>
using namespace std;

/*

Example:
Example 1:
Input:

n = 12345

Output:

1 2 3 4 5

Example 2:
Input:

n = 8

Output:

8

Explanation:
In the first example, the digits of the number 12345 are printed one by one from the most significant to the least significant using recursive function calls. For the second example, since the number is a single digit, it is printed as is.

Notes:
The function should print digits directly rather than returning them in any data structure.
Example 1:

Input:

Input: n = 5

Output:

5
Explanation:For a single-digit number, the function prints that digit.

Example 2:

Input:

Input: n = 12

Output:

1
2
Explanation:The digits of 12 are printed in order.

Example 3:

Input:

Input: n = 100

Output:

1
0
0
Explanation:The function correctly handles numbers with trailing zeros.

*/

void helper(int n)
{
    if (n == 0)
        return;

    helper(n / 10);         // pehle chhota number
    cout << n % 10 << endl; // baad me digit print
}

void printDigitsRecursively(int n)
{
    if (n < 0)
        n = -n; // negative handle
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }
    helper(n);
}
