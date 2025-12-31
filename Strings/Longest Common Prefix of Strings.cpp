#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> strs)
    {
        if (strs.size() == 0)
            return "";

        string ans = "";
        int i = 0;

        while (true)
        {
            char curr_ch = 0;

            for (auto str : strs)
            {

                // out of bound check
                if (i >= str.size())
                {
                    return ans;
                }

                if (curr_ch == 0)
                {
                    curr_ch = str[i]; // first string character
                }
                else if (str[i] != curr_ch)
                {
                    curr_ch = 0;
                    break; // mismatch found
                }
            }
            if (curr_ch == 0)
            {
                break;
            }
            ans.push_back(curr_ch); // common character found
            i++;
        }
        return ans;
    }
};