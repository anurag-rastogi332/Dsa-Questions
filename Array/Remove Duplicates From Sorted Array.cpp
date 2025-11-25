#include <iostream>
#include <vector>
using namespace std;

/*

Problem Description
Given a sorted array of integers nums, remove the duplicates in-place such that each unique element appears only once. The order of elements should be maintained, and you must do this using O(1) extra memory, meaning the input array itself should be modified to store the results. You may consider that the function should return the new length of the array after duplicates have been removed.

Note:
Do not allocate extra space for another array; you must do this by modifying the input array in-place with O(1) extra memory.
Example 1:

Input:

n=1 nums=[10]

Output:

1
Explanation:Only one element remains; length is 1.

Example 2:

Input:

n=4 nums=[0,0,0,0]

Output:

1
Explanation:After removing duplicates only one 0 stays → length 1.

Example 3:

Input:

n=5 nums=[1,2,3,4,5]

Output:

5
Explanation:No duplicates removed → length 5.

*/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        // Implement logic here
        int i = 1, j = 0;
        // two pointers approach
        while (i < nums.size())
        {
            if (nums[i] == nums[j])
            {
                i++;
            }
            else
            {
                j++;
                nums[j] = nums[i];
                i++;
            }
        }
        return j + 1;
    }
};