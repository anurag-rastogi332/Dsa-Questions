
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*

Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.
Input: arr[] = [10, 5, 10]
Output: 5
Explanation: The largest element of the array is 10 and the second largest element is 5.
Input: arr[] = [10, 10, 10]
Output: -1
Explanation: The largest element of the array is 10 and the second largest element does not exist.


*/

class Solution
{
public:
    int getSecondLargest(vector<int> &arr)
    {

        int n = arr.size();
        int largest = INT_MIN;
        int secondLargest = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > largest)
            {
                largest = arr[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != largest)
            {
                if (arr[i] > secondLargest)
                {
                    secondLargest = arr[i];
                }
            }
        }
        if (secondLargest == INT_MIN)
        {
            return -1;
        }

        return secondLargest;
    }
};