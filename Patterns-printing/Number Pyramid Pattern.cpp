
#include<iostream>
using namespace std;




/*

Example:
If n is 4, the output should be:


      1
    1 2
  1 2 3
1 2 3 4
Details:
The pyramid is built from a series of rows with each subsequent row having increasing numbers.
Align each row in a centered format, filling the space to the left with necessary spaces to maintain the pyramid structure.
Example 1:

Input:

n = 1

Output:

1
Explanation:Single row with one number

Example 2:

Input:

n = 2

Output:

 1 
1 2 
Explanation:Two rows showing progression of numbers

Example 3:

Input:

n = 3

Output:

  1 
 1 2 
1 2 3 
Explanation:Three rows with proper spacing

*/

class Solution {
public:
  void printNumberPyramid(int n) {
    // Implement the pattern printing logic here
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n - i; j++) {
        cout << " ";
      }
      for (int j = 1; j <= i; j++) {
        cout << j<<" ";
      }
      cout << endl;
    }
  }
};