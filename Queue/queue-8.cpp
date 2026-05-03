#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> firstNegInt(vector<int> &arr, int k)
    {
        // Process 1st window
        //  - addition
        //- answer

        // Process remaining windows
        // removal
        // addition
        // answer

        // Process 1st window
        queue<int> dq;
        vector<int> ans;
        // addition
        for (int index = 0; index < k; index++)
        {
            int element = arr[index];
            if (element < 0)
            {
                dq.push(index);
            }
        }
        // answer
        if (dq.empty())
        {
            ans.push_back(0);
        }
        else
        {
            int index = dq.front();
            // never pop here
            int element = arr[index];
            ans.push_back(element);
        }

        // Process remaining windows
        for (int i = k; i < arr.size(); i++)
        {
            // removal
            if (!dq.empty() && i - dq.front() >= k)
            {
                dq.pop();
            }
            // addition
            int element = arr[i];
            if (element < 0)
            {
                dq.push(i);
            }

            // answer
            // answer
            if (dq.empty())
            {
                ans.push_back(0);
            }
            else
            {
                int index = dq.front();
                // never pop here
                int element = arr[index];
                ans.push_back(element);
            }
        }

        return ans;
    }
};