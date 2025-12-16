#include <iostream>
#include <algorithm>
using namespace std;

/*

Example 1:

Input: order = "cba", s = "abcd"

Output: "cbad"

Explanation: "a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a".

Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

Example 2:

Input: order = "bcafg", s = "abcd"

Output: "bcad"

Explanation: The characters "b", "c", and "a" from order dictate the order for the characters in s. The character "d" in s does not appear in order, so its position is flexible.

Following the order of appearance in order, "b", "c", and "a" from s should be arranged as "b", "c", "a". "d" can be placed at any position since it's not in order. The output "bcad" correctly follows this rule. Other arrangements like "dbca" or "bcda" would also be valid, as long as "b", "c", "a" maintain their order.


Constraints:

1 <= order.length <= 26
1 <= s.length <= 200
order and s consist of lowercase English letters.
All the characters of order are unique

*/

string orderCopy;
class Solution
{
public:
    static bool cmp(char ch1, char ch2)
    {
        // main sort krna chahata hu as per the order string
        // if ch1 is present before ch2 in order string
        //  then place ch1 before ch2 in string s
        //  and vice versa
        return (orderCopy.find(ch1) < orderCopy.find(ch2));
    }
    string customSortString(string order, string s)
    {
        orderCopy = order;
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};