#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// ✅ Monotonic Stack Pattern 🔥

/*
Input: arr[] = [4, 8, 5, 2, 25]
Output: [2, 5, 2, -1, -1]
Explanation:
The first element smaller than 4 having index > 0 is 2.
The first element smaller than 8 having index > 1 is 5.
The first element smaller than 5 having index > 2 is 2.
There are no elements smaller than 4 having index > 3.
There are no elements smaller than 4 having index > 4.
Input: arr[] = [13, 7, 6, 12]
Output: [7, 6, -1, -1]
Explanation:
The first element smaller than 13 having index > 0 is 7.
The first element smaller than 7 having index > 1 is 6.
There are no elements smaller than 6 having index > 2.
There are no elements smaller than 12 having index > 3.

Input: arr[] = [4, 1]
Output: [1, -1]
Explanation: 4 will be updated to 1 and 1 will be updated to -1.


*/

class Solution
{
public:
    vector<int> solve(vector<int> &arr, vector<int> &ans, stack<int> &s)
    {

        int n = arr.size();

        for (int i = n - 1; i >= 0; i--)
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

    vector<int> nextSmallerEle(vector<int> &arr)
    {

        vector<int> ans;
        stack<int> s;
        s.push(-1);

        vector<int> result = solve(arr, ans, s);
        reverse(result.begin(), result.end()); // kyunki hum end se fill kar rahe the

        return result;
    }
};

/*
Short Algorithm (Next Smaller Element – Right Side)

Initialize an empty stack and push -1 (represents “no smaller element”).

Traverse the array from right to left.

For each element:

While the stack top is greater than or equal to the current element, pop it.

The stack top now gives the next smaller element (or -1 if none).

Store stack.top() in the answer array.

Push the current element into the stack.

Reverse the answer array to match the original order.

Return the result.

One-line memory trick:
“Scan from right, pop bigger or equal, top is the next smaller.”

*/

/*
🔁 Same Pattern, Other Questions (Quick Recall)

This is the same Monotonic Stack pattern. With tiny changes, you can solve:

Previous Smaller Element (scan left → right, pop >=)

Next Greater Element (scan right → left, pop <=)

Previous Greater Element (scan left → right, pop <=)

And big problems like:

Largest Rectangle in Histogram

Stock Span

Daily Temperatures

*/