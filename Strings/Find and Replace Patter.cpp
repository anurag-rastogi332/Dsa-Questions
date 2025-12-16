#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


/*

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}.
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
Example 2:

Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]


Constraints:

1 <= pattern.length <= 20
1 <= words.length <= 50
words[i].length == pattern.length
pattern and words[i] are lowercase English letters.

*/

class Solution
{
public:
    string normaliseString(string &str)
    {
        // is function me main her ek string ko standard formet me convert kr dunga
        // creating mapping
        char start = 'a';
        unordered_map<char, char> mapping;
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            if (mapping.find(ch) == mapping.end())
            {
                // sgar pehle se mapping ni hai create a record
                mapping[ch] = start;
                start++;
            }
        }
        // usemapping
        string ansString = "";
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];
            char mappedCharacter = mapping[ch];
            // original character ko hi replace kr diya
            // if you want,then you can create a new normalised string
            ansString.push_back(mappedCharacter);
        }
        return ansString;
    }
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> ans;
        string newPattern = normaliseString(pattern);

        for (int i = 0; i < words.size(); i++)
        {
            string currentWord = words[i];
            string newCurrentWord = normaliseString(currentWord);
            // i just have to check the normalise string with normalised patter string
            if (newPattern == newCurrentWord)
            {
                // include in answer
                ans.push_back(currentWord);
            }
        }
        return ans;
    }
};