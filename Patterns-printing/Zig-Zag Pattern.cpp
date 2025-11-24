


/*

*       *
 *     *
  *   *
   * *
    *
   * *
  *   *
 *     *
*       *


Example
If n = 4, the expected output pattern is as shown above.

Example 1:

Input:

n=3

Output:

*     *
 *   *
  * *
   *
  * *
 *   *
*     *
Explanation:A zig-zag pattern with 3 rows.

Example 2:

Input:

n=4

Output:

*       *
 *     *
  *   *
   * *
    *
   * *
  *   *
 *     *
*       *
Explanation:A zig-zag pattern with 4 rows.

Example 3:

Input:

n=5

Output:

*         *
 *       *
  *     *
   *   *
    * *
     *
    * *
   *   *
  *     *
 *       *
*         *
Explanation:A zig-zag pattern with 5 rows.



*/

#include <iostream>
using namespace std;

class Solution {
public:
    void printZigZag(int n) {
        // ---- Part 1 (Upper Half) ----
        int maxSpace = 2 * n - 1;

        for (int row = 1; row <= n; row++) {
            // leading spaces
            for (int col = 1; col <= row - 1; col++) {
                cout << " ";
            }

            // star
            cout << "*";

            // middle spaces
            for (int col = 1; col <= maxSpace; col++) {
                cout << " ";
            }

            // star
            cout << "*";
            cout << endl;

            maxSpace -= 2;
        }

        // ---- Part 2 (Lower Half) ----
        int npart2 = n + 1;
        for (int row = 1; row <= npart2; row++) {
            // leading spaces
            for (int col = 1; col <= npart2 - row; col++) {
                cout << " ";
            }

            // stars
            if (row == 1) {
                cout << "*";
            } else {
                cout << "*";
                for (int col = 1; col <= 2 * row - 3; col++) {
                    cout << " ";
                }
                cout << "*";
            }
            cout << endl;
        }
    }
};
