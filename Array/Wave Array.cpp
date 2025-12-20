#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// gfg -> https://www.geeksforgeeks.org/problems/wave-array-1587115621/1

/*

Examples:

Input: arr[] = [1, 2, 3, 4, 5]
Output: [2, 1, 4, 3, 5]
Explanation: Array elements after sorting it in the waveform are 2, 1, 4, 3, 5.
Input: arr[] = [2, 4, 7, 8, 9, 10]
Output: [4, 2, 8, 7, 10, 9]
Explanation: Array elements after sorting it in the waveform are 4, 2, 8, 7, 10, 9.
Input: arr[] = [1]
Output: [1]

*/

class Solution
{
public:
    void sortInWave(vector<int> &arr)
    {

        int n = arr.size();

        for (int i = 0; i + 1 < n; i += 2)
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
};