#include <iostream>
#include <unordered_map>
using namespace std;

// leet code-> https://leetcode.com/problems/decode-the-message/description/
/*

You are given the strings key and message, which represent a cipher key and a secret message, respectively. The steps to decode message are as follows:

Use the first appearance of all 26 lowercase English letters in key as the order of the substitution table.
Align the substitution table with the regular English alphabet.
Each letter in message is then substituted using the table.
Spaces ' ' are transformed to themselves.
For example, given key = "happy boy" (actual key would have at least one instance of each letter in the alphabet), we have the partial substitution table of ('h' -> 'a', 'a' -> 'b', 'p' -> 'c', 'y' -> 'd', 'b' -> 'e', 'o' -> 'f').
Return the decoded message.


Example 1:


Input: key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
Output: "this is a secret"
Explanation: The diagram above shows the substitution table.
It is obtained by taking the first appearance of each letter in "the quick brown fox jumps over the lazy dog".
Example 2:


Input: key = "eljuxhpwnyrdgtqkviszcfmabo", message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb"
Output: "the five boxing wizards jump quickly"
Explanation: The diagram above shows the substitution table.
It is obtained by taking the first appearance of each letter in "eljuxhpwnyrdgtqkviszcfmabo".


*/

class Solution
{
public:
    void createMapping(unordered_map<char, char> &mapping, string key)
    {
        char start = 'a';

        for (int i = 0; i < key.length(); i++)
        {
            // mereko sirf usi character ki mapping store krni hai
            // jiski mapping pehle se store nhi hai
            char ch = key[i];
            if (mapping.find(ch) == mapping.end())
            {
                // create or store mapping,if not present
                mapping[ch] = start;
                start++;
            }
        }
    }
    
    string useMapping(unordered_map<char, char> &mapping, string message)
    {
        string s = "";
        for (int i = 0; i < message.length(); i++)
        {
            char ch = message[i];
            // find mapped character
            char mappedCharacter = mapping[ch];
            // include this in ans string
            s.push_back(mappedCharacter);
        }
        return s;
    }
    string decodeMessage(string key, string message)
    {
        // step-1 -> create mapping
        unordered_map<char, char> mapping;
        char space = ' ';
        mapping[space] = space;
        createMapping(mapping, key);
        // step-2 -> use mapping

        string ans = useMapping(mapping, message);
        return ans;
    }
};