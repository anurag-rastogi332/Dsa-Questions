#include <iostream>
#include <queue>
using namespace std;

/*

Input: q[] = [2, 4, 3, 1]
Output: [2, 3, 4, 1]
Explanation: We place the first element of the first half 2 and after that
place the first element of second half 3 and after that repeat
the same process one more time so the resulting queue will be [2, 3, 4, 1]
Input: q[] = [3, 5]
Output: [3, 5]
Explanation: We place the first element of the first half 3 and first element
of the second half 5 so the resulting queue is [3, 5]

*/

class Solution
{
public:
    void rearrangeQueue(queue<int> &q)
    {
        queue<int> q1;
        int size = q.size();
        int half = size / 2;
        while (half--)
        {
            int element = q.front();
            q.pop();
            q1.push(element);
        }
        // toh ab mere pass 2 queue hai
        // with size/2 elements each
        //  apply main logic->fetch,pop,insert
        while (!q1.empty())
        {
            int element = q1.front();
            q1.pop();
            q.push(element);
            element = q.front();
            q.pop();
            q.push(element);
        }
    }
};