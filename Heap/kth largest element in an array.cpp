#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// leetcode -> 215

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        // iitial state
        for (int i = 0; i < k; i++)
        {
            pq.push(nums[i]);
        }
        // main logic - bade element pr dependant
        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        int ans = pq.top();
        return ans;
    }
};