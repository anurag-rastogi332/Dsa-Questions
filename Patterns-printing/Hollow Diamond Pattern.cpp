#include <iostream>
using namespace std;

/*

Example 1:

Input:

n = 1

Output:

*
Explanation:Smallest possible diamond with single star

Example 2:

Input:

n = 2

Output:

 *
* *
 *
Explanation:Diamond with height 3 (2*n-1)

Example 3:

Input:

n = 3

Output:

  *
 * *
*   *
 * *
  *
Explanation:Diamond with height 5 showing hollow structure

*/

class Solution
{
public:
    void printHollowDiamond(int n)
    {
        // Top half including middle
        for (int i = 1; i <= n; i++)
        {
            // Print leading spaces
            for (int j = 1; j <= n - i; j++)
                cout << " ";

            if (i == 1)
            {
                cout << "*";
            }
            else
            {
                cout << "*";
                for (int j = 1; j <= 2 * i - 3; j++)
                    cout << " ";
                cout << "*";
            }
            cout << endl;
        }

        // Bottom half
        for (int i = n - 1; i >= 1; i--)
        {
            // Print leading spaces
            for (int j = 1; j <= n - i; j++)
                cout << " ";

            if (i == 1)
            {
                cout << "*";
            }
            else
            {
                cout << "*";
                for (int j = 1; j <= 2 * i - 3; j++)
                    cout << " ";
                cout << "*";
            }
            cout << endl;
        }
    }
};
