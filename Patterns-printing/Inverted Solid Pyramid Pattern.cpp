
#include<iostream>
using namespace std;

/*

Example
Consider n = 3:


*****
 ***
  *
Explanation:

The first row has 5 stars (2*3 - 1) and no leading spaces.
The second row has 3 stars and 1 leading space.
The third row contains 1 star with 2 leading spaces.
Your task is to implement the function such that it generates the correct pattern for any valid value of n.

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

* * * 
  * 
Explanation:An inverted solid pyramid with two rows.

Example 3:

Input:

n=3

Output:

* * * * * 
  * * * 
    * 
Explanation:An inverted solid pyramid with three rows.

*/




class Solution {
public:
  void printInvertedSolidPyramid(int n) {

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i - 1; j++) {
        cout << "  ";
      }
      for (int k = 1; k <= 2 * (n - i) + 1; k++) {
        cout << "* ";
      }
      cout << endl;
    }
  }
}
;