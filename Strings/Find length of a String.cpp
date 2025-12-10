#include <iostream>
using namespace std;

/*

Example:
Input: "OpenAI"

Output: 6

Explanation: The string "OpenAI" has six characters: 'O', 'p', 'e', 'n', 'A', and 'I'. Thus, the length is 6.

Example 1:

Input:

Input: 'hello'

Output:

5
Explanation:The string 'hello' has 5 characters.

Example 2:

Input:

Input: 'world!'

Output:

6
Explanation:The string 'world!' has 6 characters.

Example 3:

Input:

Input: 'openai'

Output:

6
Explanation:The string 'openai' has 6 characters.

*/

int findStringLength(const string &input)
{
    return input.length();
}