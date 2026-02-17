#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//  “This problem is solved using the Monotonic Stack pattern to find nearest smaller elements.”

/*

Previous Smaller Element
Difficulty: MediumAccuracy: 67.52%Submissions: 7K+Points: 4
You are given an integer array arr[ ]. For every element in the array, your task is to determine its Previous Smaller Element (PSE).

The Previous Smaller Element (PSE) of an element x is the first element that appears to the left of x in the array and is strictly smaller than x.

Note: If no such element exists, assign -1 as the PSE for that position.

Examples:

Input: arr[] = [1, 6, 2]
Output: [-1, 1, 1]
Explanation:
For 1, there is no element on the left, so answer is -1.
For 6, previous smaller element is 1.
For 2, previous smaller element is 1.
Input: arr[] = [1, 5, 0, 3, 4, 5]
Output: [-1, 1, -1, 0, 3, 4]
Explanation:
For 1, no element on the left, so answer is -1.
For 5, previous smaller element is 1.
For 0, no element on the left smaller than 0, so answer is -1.
For 3, previous smaller element is 0.
For 4, previous smaller element is 3.
For 5, previous smaller element is 4.

*/

class Solution
{
public:
    vector<int> solve(vector<int> &arr, vector<int> &ans, stack<int> &s)
    {

        int n = arr.size();

        for (int i = 0; i < n; i++)
        {

            int element = arr[i];

            while (s.top() != -1 && s.top() >= element)
            {
                s.pop();
            }

            // agar main yaha tak aaya it means
            // chota element stack ke top per hai
            // ya -1 stack ke top per hai
            ans.push_back(s.top());
            s.push(element);
        }

        return ans;
    }

    vector<int> prevSmaller(vector<int> &arr)
    {
        vector<int> ans;
        stack<int> s;
        s.push(-1);

        vector<int> result = solve(arr, ans, s);
        return result;
    }
};

/*

Short Algorithm (1-minute memory version)

Previous Smaller Element using Stack

Create an empty stack and push -1 as a base (means “no smaller found”).

Traverse the array from left to right.

For each element:

Pop elements from the stack while they are greater than or equal to the current element.

The stack top now holds the previous smaller element (or -1 if none).

Store stack.top() in the answer.

Push the current element into the stack.

The answer array is your result.

One-line memory trick:
“While top is bigger or equal, pop it. Top after popping is the previous smaller.”
*/

/*

🚀 Big Problems That Use This Exact Idea

Once you know this pattern, you can solve:

✅ Largest Rectangle in Histogram

✅ Stock Span Problem

✅ Daily Temperatures (LeetCode)

✅ Maximum Area in Histogram

✅ Next Greater Element I / II

✅ Sum of Subarray Minimums

All of these boil down to:

“Find nearest smaller/greater element on left/right using a monotonic stack.”
*/