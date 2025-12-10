#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*

Example 1:
Input:

"A man, a plan, a canal: Panama"

Output:

true

Explanation:

After removing non-alphanumeric characters and converting to lowercase, the string becomes "amanaplanacanalpanama", which is a palindrome.

Example 2:
Input:

"race a car"

Output:

false

Explanation:

The processed string becomes "raceacar", which is not a palindrome.

Write a function to return true if the given string is a valid palindrome, or false otherwise.

Example 1:

Input:

s="A man, a plan, a canal: Panama"

Output:

true
Explanation:Ignoring cases and non-alphanumeric characters, 'AmanaplanacanalPanama' is a palindrome.

Example 2:

Input:

s="race a car"

Output:

false
Explanation:After removing non-alphanumeric characters and ignoring cases, 'raceacar' is not a palindrome.

Example 3:

Input:

s=" "

Output:

true
Explanation:An empty string is considered a valid palindrome.

*/

class Solution
{
public:
  bool isAnagram(const string &s, const string &t)
  {
    unordered_map<char, int> count;

    for (int i = 0; i < s.length(); i++)
    {
      char ch = s[i];
      count[ch]++;
    }

    for (int j = 0; j < t.length(); j++)
    {
      char ch = t[j];
      count[ch]--;
    }
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
      if (count[ch] != 0)
      {
        return false;
      }
    }
    return true;
  }
};