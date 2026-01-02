#include <iostream>
#include <vector>
using namespace std;

/*

Example:
Input:


s = ['h', 'e', 'l', 'l', 'o']
Output:

After executing the function, the array s should be modified to:


['o', 'l', 'l', 'e', 'h']

*/

class Solution
{
    void reverseHelper(vector<char> &s, int start, int end)
    {
        if (start >= end)
            return; // Base case
        // pehla case mai solve krlunga
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        // baki case recursion solve kr dega
        reverseHelper(s, start + 1, end - 1);
    }

public:
    vector<char> reverseString(vector<char> &s)
    {
        reverseHelper(s, 0, s.size() - 1);
        return s;
    }
};