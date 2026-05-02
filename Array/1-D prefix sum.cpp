#include <iostream>
#include <vector>
using namespace std;

/*

Input: arr[] = [10, 20, 10, 5, 15]
Output: [10, 30, 40, 45, 60]
Explanation: For each index i, add all the elements from 0 to i:
prefixSum[0] = 10,
prefixSum[1] = 10 + 20 = 30,
prefixSum[2] = 10 + 20 + 10 = 40 and so on.
Input: arr[] = [30, 10, 10, 5, 50]
Output: [30, 40, 50, 55, 105]
Explanation: For each index i, add all the elements from 0 to i:
prefixSum[0] = 30,
prefixSum[1] = 30 + 10 = 40,
prefixSum[2] = 30 + 10 + 10 = 50 and so on


*/

class Solution
{
public:
    vector<int> prefSum(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prefix(n);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        return prefix;
    }
};



