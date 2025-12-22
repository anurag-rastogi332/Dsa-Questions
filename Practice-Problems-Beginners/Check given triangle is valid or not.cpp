#include <iostream>
using namespace std;

/*

Input format
Three space-separated numbers representing the sides of the triangle.

Output format
Print Yes if a valid triangle can be formed, otherwise print No.

Example 1:

Input: a=29 b=37 c=18

Output: Yes

Explanation: The sum of any two sides is greater than the third side, so the triangle is valid.

Example 2:

Input: a=44 b=26 c=48

Output: 'Yes'

Explanation: The sum of any two sides is greater than the third side, so the triangle is valid.

Example 3:

Input: a=336366944 b=34259552 c=827373662

Output: 'No'

Explanation: The sum of any two sides is not greater than the third side, so the triangle is not valid.

*/

class Solution {
public:
  string isValidTriangle(int a, int b, int c) {

    if ((a + b) > c && (b + c) > a && (a + c) > b) {
      return "Yes";
    }
    return "No";
  }
};