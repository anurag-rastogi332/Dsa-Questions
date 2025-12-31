#include <iostream>
#include <vector>
using namespace std;

/*

Example
Input:

arr = [2, 3, 5, 6, 8, 11] n = 6

Output:

2 6 8

Explanation:

The numbers 2, 6, and 8 from the array are even numbers, and hence they are printed.
The numbers 3, 5, and 11 are odd, so they are not printed.
Example 1:

Input:

Input: n = 5, arr = [1, 2, 3, 4, 5]

Output:

2 4
Explanation:Only even numbers in [1, 2, 3, 4, 5] are 2 and 4.

Example 2:

Input:

Input: n = 4, arr = [10, 21, 32, 45]

Output:

10 32
Explanation:Even numbers in [10, 21, 32, 45] are 10 and 32.

Example 3:

Input:

Input: n = 6, arr = [2, 4, 6, 8, 10, 12]

Output:

2 4 6 8 10 12
Explanation:All numbers are even.

*/

vector<int> printEvenNumbers(vector<int> &arr, int index)
{
    // Base case
    if (index >= arr.size())
        return {};

    // Recursive case
    std::vector<int> result = printEvenNumbers(arr, index + 1);

    if (abs(arr[index]) % 2 == 0)
    {                                              // Checking for even number including handling negative numbers
        result.insert(result.begin(), arr[index]); // Inserting at the start to retain left-right order
    }

    return result;
}