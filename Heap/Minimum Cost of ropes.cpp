#include <iostream>
#include <queue>
using namespace std;

/*

Input: arr[] = [4, 3, 2, 6]
Output: 29
Explanation: First connect 2 and 3 to get [4, 5, 6] with a cost of 5, then connect 4 and 5 to get [9, 6] with a cost of 9, and finally connect 9 and 6 to get one rope with a cost of 15, giving a total minimum cost of 29. Any other order, such as connecting 4 and 6 first, results in a higher total cost of 38.
Input: arr[] = [4, 2, 7, 6, 9]
Output: 62
Explanation: First, connect ropes 4 and 2, which makes the array [6, 7, 6, 9]. Cost of this operation 4 + 2 = 6. Next, add ropes 6 and 6, which results in [12, 7, 9]. Cost of this operation 6 + 6 = 12. Then, add 7 and 9, which makes the array [12,16]. Cost of this operation 7 + 9 = 16. And finally, add these two which gives [28]. Hence, the total cost is 6 + 12 + 16 + 28 = 62.
Input: arr[] = [10]
Output: 0
Explanation: Since there is only one rope, no connections are needed, so the cost is 0.

*/

class Solution
{
public:
    int minCost(vector<int> &arr)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        // sare element insert krdo
        for (int i = 0; i < arr.size(); i++)
        {
            pq.push(arr[i]);
        }
        int totalCost = 0;
        while (pq.size() > 1)
        {
            int element1 = pq.top();
            pq.pop();
            int element2 = pq.top();
            pq.pop();
            int sum = element1 + element2;
            // use sum for combined length as well as totalCost
            pq.push(sum);
            totalCost = totalCost + sum;
        }
        return totalCost;
    }
};