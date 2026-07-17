#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

/*

You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation:
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]

*/

class Info
{
public:
    int data;
    int rIndex;
    int cIndex;

    Info(int val, int r, int c)
    {
        data = val;
        rIndex = r;
        cIndex = c;
    }
};

class compare
{
public:
    bool operator()(Info *a, Info *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        priority_queue<Info *, vector<Info *>, compare> pq;

        vector<int> ans;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int totalRows = nums.size();
        // process k elements
        /// first element of each lists
        for (int i = 0; i < totalRows; i++)
        {
            int element = nums[i][0];
            Info *temp = new Info(element, i, 0);
            pq.push(temp);
            mini = min(mini, element);
            maxi = max(maxi, element);
        }
        // can be treated as first k elements ka answer
        int ansStart = mini;
        int ansEnd = maxi;
        // main logic
        while (!pq.empty())
        {
            Info *front = pq.top();
            pq.pop();

            int element = front->data;
            int rowIndex = front->rIndex;
            int colIndex = front->cIndex;

            // main hamesha ye bhul jata hu
            mini = element;

            if ((maxi - mini) < (ansEnd - ansStart))
            {
                // iska mtlb hume koi new and small range milgyi
                ansStart = mini;
                ansEnd = maxi;
            }
            // find totalCOlumn in current array
            int totalColumn = nums[rowIndex].size();
            if (colIndex + 1 < totalColumn)
            {
                int element = nums[rowIndex][colIndex + 1];
                Info *temp = new Info(element, rowIndex, colIndex + 1);
                pq.push(temp);
                // yaha pr ferse bhula
                maxi = max(maxi, element);
            }
            else
            {
                // rukjana
                break;
            }
        }
        ans.push_back(ansStart);
        ans.push_back(ansEnd);
        return ans;
    }
};