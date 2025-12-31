#include <iostream>
using namespace std;

/*

Example
Input:

n = 5

Output:

120

Explanation:

5! = 5 * 4 * 3 * 2 * 1 = 120.
Input:

n = 0

Output:

1

Explanation:

0! = 1 (by definition).

*/
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}