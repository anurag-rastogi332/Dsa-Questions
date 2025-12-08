#include <iostream>
#include <vector>
using namespace std;

/*

Example:
Input: nums = [1, 1, 2, 3, 3, 4, 4, 8, 8]

Output: 2

Explanation: Here, each element appears twice except for 2, which appears only once. Therefore, 2 is the single non-duplicate element in the array.

Example 1:

Input:

Input: [1,1,2,3,3,4,4,8,8]

Output:

2
Explanation:The unique element in the array is 2.

Example 2:

Input:

Input: [3,3,7,7,10,11,11]

Output:

10
Explanation:The unique element in the array is 10.

Example 3:

Input:

Input: [1,1,2,2,3]

Output:

3
Explanation:The unique element in the array is 3.

*/

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int s = 0;
        int e = n - 1;

        while (s <= e)
        {

            if (s == e)
            {
                // single element
                return nums[s];
            }

            int mid = (s + e) / 2;

            int currentValue = nums[mid];

            int leftValue = -1;
            if (mid - 1 >= 0)
            {
                leftValue = nums[mid - 1];
            }

            int rightValue = -1;
            if (mid + 1 < n)
            {
                rightValue = nums[mid + 1];
            }

            // check current value is a answer or not

            if (currentValue != leftValue && currentValue != rightValue)
            {
                return currentValue;
            }

            // logic for movement to left right

            if (currentValue == leftValue && currentValue != rightValue)
            {
                // agar currentvalue==leftvalue hai to ye ek duplicate pair hai to iska matlb pair ka starting index left value ke index ke equal hai
                // iska matlb pair starting index left value ka index hai
                // left value ka index mid-1;
                // agar mai ans ke left me hu to starting index of pair even hoga
                // agar mai answer ke right me hu , to starting index of pair odd hoga
                int pairStartingIndex = mid - 1;
                if (pairStartingIndex & 1)
                {
                    // odd case -> yaani ye pair answer k right me h, iska matlb mujhe
                    // left jana hai padega
                    e = mid - 1;
                }
                else
                {
                    // right s=mid+1;
                    s = mid + 1;
                }
            }

            if (currentValue != leftValue && currentValue == rightValue)
            {
                // yaha current value to right value ke equal ho gayi iska matlb pair ka
                // starting index current value ka index hoga current value ka starting
                // index mid hai
                int pairStartingIndex = mid;
                // agar mai ans ke left me hu to starting index of pair even hoga
                // agar mai answer ke right me hu , to starting index of pair odd hoga
                if (pairStartingIndex & 1)
                {
                    // odd case -> yaani ye pair answer k right me h, iska matlb mujhe
                    // left jana hai padega
                    e = mid - 1;
                }
                else
                {
                    // right s=mid+1;
                    s = mid + 1;
                }
            }
        }
    }
};