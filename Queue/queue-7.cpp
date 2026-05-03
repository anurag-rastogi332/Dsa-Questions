#include <iostream>
#include <queue>
using namespace std;

class Solution
{
public:
    queue<int> rearrangeQueue(queue<int> q)
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
        // toh ab mere paas 2 queue h
        // with size/2 elements each
        // appply main logic -> fetch , pop. insert
        while (!q.empty())
        {
            int element = q1.front();
            q1.pop();
            q1.push(element);

            element = q.front();
            q.pop();
            q1.push(element);
        }

        return q1;
    }
};