
#include<iostream>
using namespace std;

/*

Example
For n = 4, the output should be:


   *
  ***
 *****
*******
Here, the pyramid is built with 4 rows, where each row is centered by adjusting the spaces on either side of the asterisks.

Your task is to write a function that generates this pattern for any valid input of n within the specified constraints.

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
Explanation:A solid pyramid with two rows.

Example 3:

Input:

n=3

Output:

    * 
  * * * 
* * * * * 
Explanation:A solid pyramid with three rows.

*/


class Solution {
public:
    void printSolidPyramid(int n) {
        for (int row = 0; row < n; row++) {
            // Print double-spaces for alignment
            for (int col = 0; col < (n - row - 1); col++) {
                cout << "  ";
            }

            // Print stars with space
            for (int k = 0; k < (2 * row + 1); k++) {
                cout << "* ";
            }

            cout << endl;
        }
    }
};
