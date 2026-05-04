#include <iostream>
#include <deque>
#include <vector>
using namespace std;

/*    Leetcode->239

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.



Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
1 [3  -1  -3] 5  3  6  7       3
1  3 [-1  -3  5] 3  6  7       5
1  3  -1 [-3  5  3] 6  7       5
1  3  -1  -3 [5  3  6] 7       6
1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length

*/

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
            // mujhe har element ka index ko store   krna hai
            // isme   koi shaw nhi hai
            // current element k index ko ignore krne ka mrere pass koi logci nhi h
            // thats why store toh krna hi padega
            // but isko store krne se pehle koi agar iske left me koi chota element already insert ho chuka hai to mujhe vo sab remove krne padenge
            //  kyunki vo element cannot be the answer over cannot be in the front as the current element is larger
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
            // addtion
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