#include <iostream>
#include <vector>

/*

Example:
Input:

arr = [4, 2, 7, 3, 8] target = 7

Output:

2

Explanation: The element 7 is found at index 2.

Input:

arr = [1, 2, 3, 4, 5] target = 6

Output:

-1

Explanation: The element 6 is not present in the array.

Example 1:

Input:

Input: n = 5, arr = [1, 2, 3, 4, 5], target = 3

Output:

2
Explanation:The target 3 is found at index 2.

Example 2:

Input:

Input: n = 4, arr = [7, 8, 9, 10], target = 5

Output:

-1
Explanation:The target 5 is not in the array, so -1 is returned.

Example 3:

Input:

Input: n = 6, arr = [10, 20, 30, 40, 50, 60], target = 40

Output:

3
Explanation:The target 40 is found at index 3.

*/
using namespace std;

int searchElementRecursive(const vector<int> &arr, int target, int index)
{
    if (index == arr.size())
    {
        return -1;
    }
    if (arr[index] == target)
    {
        return index;
    }
    return searchElementRecursive(arr, target, index + 1);
}