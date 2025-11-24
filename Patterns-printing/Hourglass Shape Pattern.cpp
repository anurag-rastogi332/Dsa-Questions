
#include<iostream>
using namespace std;


/*

Example
For n = 4, the output would be:


********
 ******
  ****
   **
   **
  ****
 ******
********
Here, the top four rows decrease and indent, while the last four rows increase and de-indent to complete the hourglass shape.

Example 1:

Input:

n=2

Output:

****
 **
 **
****
Explanation:An hourglass pattern with 2 rows in each half.

Example 2:

Input:

n=3

Output:

******
 ****
  **
  **
 ****
******
Explanation:An hourglass pattern with 3 rows in each half.

Example 3:

Input:

n=4

Output:

********
 ******
  ****
   **
   **
  ****
 ******
********
Explanation:An hourglass pattern with 4 rows in each half.

*/

class Solution {
public:
  void printHourglass(int n) {
    // Implement the pattern printing logic here
    // part-1
    for (int i=1; i <= n; i++) {
      // spaces
      for (int j=1; j <= i - 1; j++) {
        cout << " ";
      }
      // stars
      for (int j = 1; j <= 2 * (n - i + 1); j++) {
        cout << "*";
      }
      cout << endl;
    }
    // part 2

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n - i; j++) {
        cout << " ";
      }
      for (int j = 1; j <= 2 * i; j++) {
        cout << "*";
      }
      cout << endl;
    }
  }
};