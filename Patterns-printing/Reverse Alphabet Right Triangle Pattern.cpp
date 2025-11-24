



/*

Example:

Input:


n = 5
Output:


    E
   DE
  CDE
 BCDE
ABCDE
Example 1:

Input:

n = 1

Output:

A
Explanation:Single letter pattern

Example 2:

Input:

n = 2

Output:

B
AB
Explanation:Two row pattern without spaces

Example 3:

Input:

n = 3

Output:

C
BC
ABC
Explanation:Three row pattern as shown in example

*/


#include <iostream>
using namespace std;

class Solution {
public:
  void printReverseAlphabetTriangle(int n) {
    for (int i = 1; i <= n; i++) {
      // spaces
      for (int j = 1; j <= n - i; j++) {
        cout << ""; 
      }

      // alphabets
      for (int j = (n - i) + 65; j <= (n - i) + 65 + (i - 1); j++) {
        cout << char(j);
      }

      cout << endl;
    }
  }
};
