#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/*

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4


*/

class Solution
{
public:
    void nextSmallerElement(vector<int> &heights, vector<int> &nextAns)
    {
        stack<int> st;
        st.push(-1);
        int n = heights.size();
        for (int i = n - 1; i >= 0; i--)
        {
            int element = heights[i];
            while (st.top() != -1 && heights[st.top()] >= element)
            {
                st.pop();
            }
            // agar yaha tak pahuncha hu iska mtlb ya to koi chota number top pe rhai ya to -1 top per hai
            nextAns.push_back(st.top());
            // current number ko toh stack me push krna hai
            st.push(i);
        }
    }

    void prevSmallerElement(vector<int> &heights, vector<int> &prevAns)
    {
        stack<int> st;
        st.push(-1);
        int n = heights.size();
        for (int i = 0; i < n; i++)
        {
            int element = heights[i];
            while (st.top() != -1 && heights[st.top()] >= element)
            {
                st.pop();
            }
            // agar yaha tak pahuncha hu iska mtlb ya to koi chota number top pe rhai ya to -1 top per hai
            prevAns.push_back(st.top());
            // current number ko toh stack me push krna hai
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> nextAns;
        vector<int> prevAns;
        nextSmallerElement(heights, nextAns);
        reverse(nextAns.begin(), nextAns.end());
        // yahi main bhul jata hu
        for (int i = 0; i < nextAns.size(); i++)
        {
            if (nextAns[i] == -1)
            {
                nextAns[i] = nextAns.size();
            }
        }
        // corner case -> == wala main bhul jata hun

        prevSmallerElement(heights, prevAns);

        int maxArea = 0;
        for (int i = 0; i < nextAns.size(); i++)
        {
            int width = nextAns[i] - prevAns[i] - 1;
            int height = heights[i];
            int currArea = width * height;
            maxArea = max(maxArea, currArea);
        }

        return maxArea;
    }
};
