#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<pair<int, int>> data;
        for (int i = 0; i < nums.size(); i++)
        {
            int index = i;
            int val = nums[i];
            data.push_back({val, index});
        }
        // ab mera vectore ready hai
        // sorting kr
        sort(data.begin(), data.end());
        // apply two ptr approach
        int s = 0;
        int e = nums.size() - 1;
        while (s < e)
        {
            int sum = data[s].first + data[e].first;
            if (sum == target)
            {
                vector<int> temp;
                temp.push_back(data[s].second);
                temp.push_back(data[e].second);
                return temp;
            }
            if (sum > target)
            {
                e--;
            }
            else
            {
                s++;
            }
        }
        vector<int> temp;
        return temp;
    }
};
