#include <iostream>
#include <stack>
using namespace std;

/*


You are given a stack of integers that is sorted in ascending order, with the smallest element at the top. Your task is to write a function that inserts a given integer x into the stack while maintaining its sorted order.

There is a critical constraint: you are not allowed to use any loops (like for or while). You must solve this problem using only the standard stack operations (push, pop, peek, isEmpty) and recursion.

Example 1:
Input:
stack = [5, 4, 2, 1] (Top of stack is 1)
x = 3
Output Stack:
[5, 4, 3, 2, 1]
Example 2:
Input:
stack = [10, 8, 4] (Top of stack is 4)
x = 9
Output Stack:
[10, 9, 8, 4]
Example 3:
Input:
stack = [5, 3, 1] (Top of stack is 1)
x = 0
Output Stack:
[5, 3, 1, 0]
Input Format
The input is the stack and an integer x to be inserted.
Output Format
The function should modify the stack in-place. The final state of the stack should have x inserted at its correct sorted position.
Example 1:

Input: stack = [5,4,2,1], x = 3

Output Stack (Top to Bottom): '1 2 3 4 5'

Example 2:

Input: stack = [10,8,4], x = 9

Output Stack (Top to Bottom): '4 8 9 10'

Example 3:

Input: stack = [5,3,1], x = 0

Output Stack (Top to Bottom): '0 1 3 5'

*/

class Solution
{
public:
    void sortedInsert(stack<int> &s, int value)
    {
        // base case
        if (s.empty())
        {
            s.push(value);
            return;
        }

        // 1 case hum, baaki recursion
        if (value <= s.top())
        {
            s.push(value);
            return;
        }
        else
        {
            // value > s.top()
            int topValue = s.top();
            s.pop();
            // recursion
            sortedInsert(s, value);
            // backtrack
            s.push(topValue);
        }
    }
};
