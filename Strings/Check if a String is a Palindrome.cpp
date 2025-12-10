#include<iostream>
using namespace std;

/*

Example:
Example 1:
Input:


s = "madam"
Output:


true
Explanation: The string "madam" reads identically forwards and backwards.

Example 2:
Input:


s = "hello"
Output:


false
Explanation: The string "hello" does not have the same sequence when read backwards.

Note:
The palindrome check is case-sensitive, meaning "Madam" and "madam" are distinct; only strings with identical sequences in both directions when case is considered will qualify as palindromes.
Example 1:

Input:

Input: "racecar"

Output:

true
Explanation:The string "racecar" reads the same forward and backward.

Example 2:

Input:

Input: "level"

Output:

true
Explanation:The string "level" is a palindrome.

Example 3:

Input:

Input: "hello"

Output:

false
Explanation:The string "hello" does not read the same forward and backward.

*/

bool isPalindrome(string s) {
  int i = 0;
  int j = s.length() - 1;
  while (i <= j) {
    if (s[i] != s[j]) {
      return false;
    } else {
      i++;
      j--;
    }
  }
  return true;
}