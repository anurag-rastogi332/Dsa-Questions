

/*

Example
Input:
n = 8
k = 2
Output:
12
Explanation:
The binary representation of 8 is 1000.
By setting the 2nd bit (0-indexed), the binary becomes 1100, which is 12 in decimal.
Note
You are expected to manipulate the integer's binary form directly.
The problem does not require an actual change in bits, just return the integer value after setting the k-th bit.
Example 1:

Input:

Input: n = 5, k = 1

Output:

7
Explanation:Binary of 5: 101 → Setting bit at position 1 → 111 (decimal 7).

Example 2:

Input:

Input: n = 8, k = 2

Output:

12
Explanation:Binary of 8: 1000 → Setting bit at position 2 → 1100 (decimal 12).

Example 3:

Input:

Input: n = 10, k = 0

Output:

11
Explanation:Binary of 10: 1010 → Setting bit at position 0 → 1011 (decimal 11).

*/

int setKthBit(int n, int k) {
  // Complete the logic here
  int mask = 1 << k;
  int ans = n | mask;
  return ans;

  /*

  Single | = Bitwise OR (works on bits). Example: 0101 | 0010 = 0111.
Double || = Logical OR (works on conditions like true/false).
So to set k-th bit, we use n | (1 << k) because bitwise OR changes the actual
bits.

  */
}
