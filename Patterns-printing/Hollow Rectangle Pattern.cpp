
#include<iostream>
using namespace std;
/*

Example
Input:

n = 4
m = 5
Output:

* * * * * 
*       * 
*       * 
* * * * * 
In this example, a rectangle of 4 rows and 5 columns is generated with a hollow inside and '*' characters on the border.

Example 1:

Input:

n=2, m=5

Output:

* * * * * 
* * * * * 
Explanation:For n=2, m=5, both rows are filled with '*' as it's only a two-row rectangle.

Example 2:

Input:

n=3, m=7

Output:

* * * * * * * 
*           * 
* * * * * * * 
Explanation:A hollow rectangle of 3 rows and 7 columns with '*' on the border.

Example 3:

Input:

n=4, m=4

Output:

* * * * 
*     * 
*     * 
* * * * 
Explanation:A hollow square-like rectangle of 4 rows and 4 columns.


*/



class Solution {
public:
  void printHollowRectangle(int n, int m) {
    // Implement the pattern printing logic here
    for (int row =1; row <= n; row++) {

      if (row == 1 || row == n) {
        for (int colm = 1; colm <= m; colm++) {
          cout << "* ";
        }
      } else {
        cout << "* ";
        for (int colm = 1; colm <= (m - 2); colm++) {
          cout << "  ";
        }
        cout<< "*  ";
      }
      cout << endl;
    }
  }
};