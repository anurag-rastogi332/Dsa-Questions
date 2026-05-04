#include <iostream>
#include <unordered_map>
#include <deque>
using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string &s)
    {

        deque<char> dq;
        string ans;
        unordered_map<char, int> freq;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            // initial state maintain
            freq[ch]++;
            dq.push_back(ch);
            // let's find the answer now
            // logic-> front k elemnt ko chekc krte raho jab tak answer na mile
            // agar answer nahi mila i.e. dq.empty() -> # store
            while (!dq.empty())
            {
                char frontElement = dq.front();
                // check whether front is the answer or not
                if (freq[frontElement] == 1)
                {
                    ans.push_back(frontElement);
                    break;
                }
                else
                {
                    // duplicate
                    dq.pop_front();
                }
            }
            // while loop se bahar 2 case me aaskte h
            // 1st case -> answer store krlia hoga -> dq empty nahi hogi
            // 2nd case -> dq empty hogyi -> # store krna padega
            if (dq.empty())
            {
                ans.push_back('#');
            }
        }
        return ans;
    }
};