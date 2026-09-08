#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.



Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]



*/

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // sabse pehle to hum map me store krenge number aur uski frequency ko
        unordered_map<int, int> map;
        for (auto x : nums)
        {
            map[x]++;
        }
        // ab hum ek max heap data structure bnayenge jo ki max elements ko top per rakhega
        // hum {frequency,number} ko rakhenge kyunki hume phir hgith freq wale ko top per milegenge aur unke second number ko store kr lenge answer me
        priority_queue<pair<int, int>> pq;
        for (auto x : map)
        {
            int nm = x.first;
            int fr = x.second;
            pq.push({fr, nm});
        }
        vector<int> ans;
        while (k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
