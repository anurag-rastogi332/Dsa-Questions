#include <iostream>
#include <string>
using namespace std;

/*

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Explanation: After removing non-alphanumeric characters and converting the string to lowercase, it becomes "amanaplanacanalpanama", which is a palindrome.
Example 2:

Input: "race a car"
Output: false
Explanation: After processing, the string becomes "raceacar", which is not a palindrome.
Note:
Use recursion to tackle this problem, by progressively checking and reducing the string until the base case condition is met.

Example 1:

Input:

s="A man, a plan, a canal: Panama"

Output:

true
Explanation:Ignoring cases and non-alphanumeric characters, 'AmanaplanacanalPanama' is a palindrome.

Example 2:

Input:

s="racecar"

Output:

true
Explanation:'racecar' is a palindrome.

Example 3:

Input:

s="madam"

Output:

true
Explanation:'madam' is a palindrome.

*/

class Solution
{
public:
    bool isValidCharacter(char ch)
    {
        if (ch >= '0' && ch <= '9')
            return true;
        if (ch >= 'a' && ch <= 'z')
            return true;
        if (ch >= 'A' && ch <= 'Z')
            return true;
        return false;
    }

    string normaliseString(string s)
    {
        string newStr = "";
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (isValidCharacter(ch))
            {
                if (ch >= 'A' && ch <= 'Z')
                    ch = ch - 'A' + 'a';
                newStr.push_back(ch);
            }
        }
        return newStr;
    }

    bool checkPalindrome(string &s, int i, int j)
    {
        // base case
        if (i >= j)
            return true;

        // one case
        if (s[i] != s[j])
            return false;

        // recursion
        return checkPalindrome(s, i + 1, j - 1);
    }

    bool isPalindrome(string s)
    {
        string newStr = normaliseString(s);
        return checkPalindrome(newStr, 0, newStr.length() - 1);
    }
};

// try to understand this code

class Solution
{
public:
    bool isPalindrome(string s)
    {
        return isPalindromeRec(s, 0, s.size() - 1);
    }

    bool isPalindromeRec(const string &s, int left, int right)
    {
        // Base case
        if (left >= right)
            return true;

        // Skip non-alphanumeric characters
        if (!isalnum(s[left]))
            return isPalindromeRec(s, left + 1, right);
        if (!isalnum(s[right]))
            return isPalindromeRec(s, left, right - 1);

        // Recursive case
        if (tolower(s[left]) != tolower(s[right]))
            return false;
        return isPalindromeRec(s, left + 1, right - 1);
    }
};