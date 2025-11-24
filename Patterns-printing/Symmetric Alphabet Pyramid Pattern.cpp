
#include<iostream>
using namespace std;


/*

Example
If the input n = 5, the output should be:


    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
On the first row, print 'A'.
On the second row, print 'A', followed by 'B', then back to 'A', with appropriate spaces for centering.
Continue this pattern, adding the next letter in the sequence and forming a symmetric reflection in each subsequent row.
Your task is to implement the pattern generation logic for any integer input n, where n represents the number of rows, and n falls within the constraints specified.

Example 1:

Input:

n=1

Output:

A
Explanation:A single row with 'A'.

Example 2:

Input:

n=2

Output:

 A
ABA
Explanation:A symmetric pyramid pattern with two rows.

Example 3:

Input:

n=3

Output:

  A
 ABA
ABCBA
Explanation:A symmetric pyramid pattern with three rows.


*/

class Solution {
public:
  void printSymmetricAlphabetPyramid(int n) {
    // Implement the pattern printing logic here
    for (int i = 1; i <= n; i++) {

      // spaces
      for (int j = 1; j <= n - i; j++) {
        cout << " ";
      }
      // left side harf
      for (char ch = 'A'; ch < 'A' + i; ch++) {
        cout << ch;
      }
      // right side half
      for (char ch = 'A' + i - 2; ch >= 'A'; ch--) {
        cout << ch;
      }
      cout << endl;
    }
  }
};