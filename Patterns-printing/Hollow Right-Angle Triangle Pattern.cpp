

#include<iostream>
using namespace std;
/*

Example
If n = 5, the resulting pattern would be:


*
**
* *
*  *
*****
Explanation:

Line 1 contains 1 star.
Line 2 contains 2 stars.
Line 3 has a star at the beginning and the end with a space in the middle.
Line 4 has a star at the beginning and the end, with two spaces in between.
Line 5 is completely filled with stars.
Example 1:

Input:

n=2

Output:

*
* *
Explanation:A hollow right-angle triangle pattern with two rows.

Example 2:

Input:

n=3

Output:

*
* *
* * *
Explanation:A hollow right-angle triangle pattern with three rows.

Example 3:

Input:

n=4

Output:

*
* *
*   *
* * * *
Explanation:A hollow right-angle triangle pattern with four rows

*/

class Solution
{
public:
    void printHollowRightAngleTriangle(int n)
    {
        // Implement the pattern printing logic here
        for (int row = 1; row <= n; row++)
        {
            if (row == 1 || row == n)
            {
                for (int colm = 1; colm <= row; colm++)
                {
                    cout << "* ";
                }
            }
            else
            {
                cout << "* ";
                for (int colm = 1; colm <= (row - 2); colm++)
                {
                    cout << "  ";
                }
                cout << "* ";
            }
            cout << endl;
        }
    }
};