#include <iostream>
#include <string>
using namespace std;

/*

Example 1:

Input:

str = 'hello', x = 'l'

Output:

3
Explanation:The last occurrence of 'l' is at index 3.

Example 2:

Input:

str = 'world', x = 'o'

Output:

1
Explanation:The last occurrence of 'o' is at index 1.

Example 3:

Input:

str = 'abcd', x = 'z'

Output:

-1
Explanation:The character 'z' is not present in the string.

Constraints

1 <= str.length <= 10^5
str consists of lowercase and uppercase English letters, digits, and symbols.
x is a single character.

*/

//   left to right solution
class Solution
{
public:
    void findLastOccLTR(string &str, char x, int index, int &ans)
    {

        // base case
        if (index >= str.size())
        {
            return;
        }

        // ek case solution
        if (str[index] == x)
        {
            ans = index; // har match pe update hota rahega
        }

        // recursion
        findLastOccLTR(str, x, index + 1, ans);
    }

    int lastIndex(string str, char x)
    {
        int ans = -1;
        findLastOccLTR(str, x, 0, ans);
        return ans;
    }
};



// right to left soltuion

class Solution
{
public:
    void findLastOccRTL(string &str, char x, int index, int &ans)
    {

        // base case
        if (index < 0)
        {
            return;
        }

        // ek case solution
        if (str[index] == x)
        {
            ans = index; // pehla match from right = last occurrence
            return;      // recursion yahin stop
        }

        // recursion
        findLastOccRTL(str, x, index - 1, ans);
    }

    int lastIndex(string str, char x)
    {
        int ans = -1;
        findLastOccRTL(str, x, str.size() - 1, ans);
        return ans;
    }
};
