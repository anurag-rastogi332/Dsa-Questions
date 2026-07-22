#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;


/*

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]

*/

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> stk;
        for (int i = n - 1; i >= 0; --i)
        {
            while (!stk.empty() && temperatures[i] >= temperatures[stk.top()])
            {
                stk.pop();
            }
            if (!stk.empty())
            {
                answer[i] = stk.top() - i;
            }
            stk.push(i);
        }
        return answer;
    }
};