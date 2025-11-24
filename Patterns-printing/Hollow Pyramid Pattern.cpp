
#include<iostream>
using namespace std;

/*

Example:
For example, if n = 5, the pattern would be:


    *
   * *
  *   *
 *     *
*********
Where each line is centered according to the base which has 2*n - 1 characters including spaces.

Example 1:

Input:

n=1

Output:

*
Explanation:A single row pyramid with one '*' for n=1.

Example 2:

Input:

n=2

Output:

  *
* * *
Explanation:A hollow pyramid with two rows.

Example 3:

Input:

n=3

Output:

    *
  *   *
* * * * *
Explanation:A hollow pyramid with three rows.

*/



class Solution
{
public:
    void printHollowPyramid(int n)
    {
        // Implement the pattern printing logic here
        for (int row = 1; row <= n; row++)
        {
            for (int colm = 1; colm <= n - row; colm++)
            {
                cout << "  ";
            }
            if (row == 1)
            {
                cout << "* ";
            }
            else if (row == n)
            {
                for (int colm = 1; colm <= (2 * n) - 1; colm++)
                {
                    cout << "* ";
                }
            }
            else
            {
                cout << "* ";
                for (int colm = 1; colm <= (2 * row) - 3; colm++)
                {
                    cout << "  ";
                }
                cout << "*";
            }
            cout << endl;
        }
    }
};