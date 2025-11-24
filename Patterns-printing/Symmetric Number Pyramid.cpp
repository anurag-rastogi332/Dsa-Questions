
#include<iostream>
using namespace std;


/*

1      1
12    21
123  321
12344321

//examples

Example 1:

Input:

n = 1

Output:

11
Explanation:Single row with just 1 and 1

Example 2:

Input:

n = 2

Output:

1  1
1221
Explanation:Two rows following the pattern rules

Example 3:

Input:

n = 3

Output:

1    1
12  21
123321
Explanation:Three rows with proper spacing

*/




class Solution {
public:
  void printPattern(int n) {

    for (int i = 1; i <= n; i++) {
      // right side numbers
      for (int j = 1; j <= i; j++) {
        cout << j;
      }
      // spaces
      for (int j = 1; j <= 2 * (n - i); j++) {
        cout << " ";
      }
      // left side numbers
      for (int j = i; j >= 1; j--) {
        cout << j;
      }
      cout << endl;
    }
  }
};