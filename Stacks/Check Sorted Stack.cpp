#include <iostream>
#include <stack>
using namespace std;

/*

Example 1:
Input: stack = [5, 4, 3, 2, 1] (Top of stack is 1)
Output: true
Explanation: 1 <= 2 <= 3 <= 4 <= 5. The stack is sorted.
Example 2:
Input: stack = [1, 2, 3] (Top of stack is 3)
Output: false
Explanation: The top element 3 is greater than the element below it (2).
Example 3:
Input: stack = [7, 4, 9, 2] (Top of stack is 2)
Output: false
Explanation: Although 2 <= 9, the element 9 is greater than 4. The entire stack must be sorted.

*/

class Solution
{
public:
    bool isSorted(stack<int> &st)
    {

        if (st.empty())
            return true;

        int prev = st.top();
        st.pop();

        while (!st.empty())
        {
            int curr = st.top();
            st.pop();

            if (curr > prev)
            {
                return false;
            }

            prev = curr;
        }
        return true;
    }
};