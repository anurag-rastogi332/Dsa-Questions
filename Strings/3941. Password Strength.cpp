#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;


class Solution
{
public:
    int passwordStrength(string password)
    {
        int strength = 0;
        unordered_set<char> st;
        for (auto ch : password)
        {
            if (st.find(ch) == st.end())
            {
                st.insert(ch);
            }
        }
        for (auto ch : st)
        {
            if (ch >= 'a' && ch <= 'z')
            {
                strength += 1;
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                strength += 2;
            }
            else if (ch >= '0' && ch <= '9')
            {
                strength += 3;
            }
            else
            {
                strength += 5;
            }
        }
        return strength;
    }
};

class Solution
{
public:
    int passwordStrength(string password)
    {
        vector<bool> seen(128, false);
        int strength = 0;
        for (auto ch : password)
        {
            if (seen[ch])
            {
                continue;
            }
            seen[ch] = true;
            if (ch >= 'a' && ch <= 'z')
            {
                strength += 1;
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                strength += 2;
            }

            else if (ch >= '0' && ch <= '9')
            {
                strength += 3;
            }

            else
            {
                strength += 5;
            }
        }

        return strength;
    }
};