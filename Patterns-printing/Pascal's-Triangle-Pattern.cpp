#include <iostream>
using namespace std;

/*

Here is an example with 5 rows:


     1
    1 1
   1 2 1
  1 3 3 1
 1 4 6 4 1
Example
Input: numRows = 5
Output: [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]
The above example shows the first 5 rows of Pascal's Triangle, which should be returned as a list of lists.

Example 1:

Input:

n = 3

Output:

1
1 1
1 2 1
Explanation:Three row Pascal's triangle

Example 2:

Input:

n = 1

Output:

1
Explanation:Single row Pascal's triangle

Example 3:

Input:

n = 2

Output:

1
1 1
Explanation:Two row Pascal's triangle

*/

class Solution
{
public:
    void printPascalsTriangle(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            int c = 1;
            for (int j = 1; j <= i; j++)
            {
                cout << c << " ";
                c = c * (i - j) / j;
            }
            cout << endl;
        }
    }
};