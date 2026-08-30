#include <iostream>
#include <vector>
using namespace std;

/*

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.

*/

class Solution
{
public:
    void merge(vector<int> &nums, int s, int e, int mid)
    {
        // yaha pe mai merge two sorted arrays ka code likhunga
        int i = s;
        int j = mid + 1;
        vector<int> temp;
        while (i <= mid && j <= e)
        {
            if (nums[i] <= nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else
            {
                temp.push_back(nums[j]);
                j++;
            }
        }
        // ab agar mere elements dono me se kisi bhi array me bach jaye then mai unko push kr dunga
        while (i <= mid)
        {
            temp.push_back(nums[i]);
            i++;
        }
        while (j <= e)
        {
            temp.push_back(nums[j]);
            j++;
        }
        // ab mai is temp ko bapas nums me copy kr dunga
        for (int k = 0; k < temp.size(); k++)
        {
            nums[s + k] = temp[k];
        }
    };

    void mergeSort(vector<int> &nums, int s, int e)
    {
        // base case
        if (s >= e)
            return;
        // 1 case mai handle karunga
        int mid = s + (e - s) / 2;
        // recusive call karunga
        mergeSort(nums, s, mid);
        mergeSort(nums, mid + 1, e);
        // yaha pe mai merge function ko call karunga jo mere arrays ko merge krega with short
        merge(nums, s, e, mid);
    }

    vector<int> sortArray(vector<int> &nums)
    {
        int end = nums.size() - 1;
        int s = 0;
        mergeSort(nums, s, end);
        return nums;
    }
};