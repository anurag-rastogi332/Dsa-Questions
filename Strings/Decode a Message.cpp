#include <iostream>
#include <string>
using namespace std;

/*

You're given a message that was encoded using a custom mapping, and the task is to decode this message. The encoding works as follows:

Each lowercase letter 'a' to 'z' is mapped to a number string in the range of '1' to '26'.
A sequence of the message string is formed by concatenating these numbers.
You are required to decode such a number string back to the original message.

Example
Input:

message = "123456"

Output

"abcdef"

Explanation
The number 1 maps to 'a', 2 to 'b', 3 to 'c', and so forth. Hence, the sequence 123456 decodes to abcdef.
Note:

The given input string will only contain numeric characters ('1' - '9'). Each number will always decode to a valid character.
Example 1:

Input:

Input: message = "123"

Output:

abc
Explanation:1 -> a, 2 -> b, 3 -> c

Example 2:

Input:

Input: message = "26"

Output:

bf
Explanation:2 -> b, 6 -> f

Example 3:

Input:

Input: message = "54321"

Output:

edcba
Explanation:5 -> e, 4 -> d, 3 -> c, 2 -> b, 1 -> a

Constraints

The length of the input string `message` is between 1 and 1000.
The input string `message` will only contain characters from '1' to '9'.
Each number in the sequence will validly map to a lowercase letter.

*/

class Solution
{
public:
    string decodeMessage(string message)
    {
        string result = "";

        for (int i = 0; i < message.length(); i++)
        {
            char ch = message[i];

            int num = ch - '0';

            char decoded = 'a' + (num - 1);

            result.push_back(decoded);
        }

        return result;
    }
};