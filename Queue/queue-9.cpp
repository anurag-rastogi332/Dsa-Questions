#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;

        // process 1st window
        // addition
        for (int index = 0; index < k; index++)
        {
            // mujhe current element kn index ko store toh krna hi h
            // isme koi shaw nahi h
            // current elemnet k index ko ignore krne ka mere paas koi logic nahi h
            // thats why store toh krna hi padega
            // but
            // isko store krne se phle agar koi iske left me chota elemnet
            // alreadyv insert ho chuka h, toh mujhe vo sab remove krne pdenge, kyoki
            // vo element cannot be the answer oer cannot be in the front as the
            // current element is larger

            while (!dq.empty() && nums[dq.back()] < nums[index])
            {
                dq.pop_back();
            }
            dq.push_back(index);
        }
        // answer
        int element = nums[dq.front()];
        ans.push_back(element);

        // remaining window
        for (int index = k; index < nums.size(); index++)
        {
            // removal
            if (!dq.empty() && dq.front() <= index - k)
            {
                dq.pop_front();
            }
            // addition
            while (!dq.empty() && nums[dq.back()] < nums[index])
            {
                dq.pop_back();
            }
            dq.push_back(index);
            // answer
            int element = nums[dq.front()];
            ans.push_back(element);
        }
        return ans;
    }
};