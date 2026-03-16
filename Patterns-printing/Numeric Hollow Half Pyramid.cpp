#include <iostream>
using namespace std;

/*

For example, if N = 5, the pattern should be:
1
12
1 3
1 4
12345

Input Format
The first line contains a single integer T, the number of test cases.
Each of the next T lines contains a single integer N.
Output Format
For each test case, print the numeric hollow half pyramid of height N. Print a blank line after each complete pattern.
Example 1:

Input:

N = 5

Output:

1
12
1 3
1  4
12345
Explanation:The numeric hollow half pyramid for N=5.

Example 2:

Input:

N = 2

Output:

1
12
Explanation:The numeric hollow half pyramid for N=2.

Example 3:

Input:

N = 3

Output:

1
12
123
Explanation:The numeric hollow half pyramid for N=3.

*/

class Solution
{
public:
    void printHollowHalfPyramid(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0 || j == i || i == n - 1)
                {
                    cout << j + 1;
                }
                else
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
};
