#include<iostream>
using namespace std;

/*

Example:
Input:

s = "hello"
c1 = 'l'
c2 = 'x'
Output:

hexxo
Explanation:
The original string is hello.
Each occurrence of the character l is replaced with x.
Thus, the resulting string is hexxo.
Note:
Ensure that the case of c1 and c2 are preserved as given in the input, meaning only those exact occurrences of c1 will be replaced with c2.
Example 1:

Input:

Input: s = "hello", c1 = 'l', c2 = 'x'

Output:

hexxo
Explanation:All occurrences of 'l' are replaced with 'x'.

Example 2:

Input:

Input: s = "apple", c1 = 'p', c2 = 'q'

Output:

aqqle
Explanation:All occurrences of 'p' are replaced with 'q'.

Example 3:

Input:

Input: s = "mississippi", c1 = 's', c2 = 'z'

Output:

mizzizzippi
Explanation:All occurrences of 's' are replaced with 'z'.

*/

string replaceCharacter(string s, char c1, char c2) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == c1) {
      s[i] = c2;
    }
  }
  return s;
}