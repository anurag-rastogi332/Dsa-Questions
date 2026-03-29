#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/*

Allocate Minimum Pages
Given a set of n books, each having a specific number of pages represented as an array arr where arr[i] denotes the number of pages in the i-th book. Your task is to allocate these books to m students such that:

Each student receives at least one book.
The books assigned to a student are contiguous.
The goal is to minimize the maximum number of pages assigned to any student.

For example, consider the following scenario:

Books: arr = [12, 34, 67, 90]
Students: m = 2
An optimal way to allocate these books might be:

Student 1: Books with pages [12, 34, 67], total pages = 113.
Student 2: Books with pages [90], total pages = 90.
In this allocation, the maximum number of pages assigned to any student is 113.

Your function should compute and return this minimal maximum number of pages.

Example
Suppose we have an allocation:


arr = [12, 34, 67, 90]
m = 2
An optimal allocation results in:

Student 1: [12, 34, 67] with total pages = 113
Student 2: [90] with total pages = 90
Thus, the minimal maximum pages assigned among students is 113.

Example 1:

Input:

arr = [12,34,67,90], k = 2

Output:

113
Explanation:Allocation can be done in following ways: {12} and {34, 67, 90} Maximum Pages = 191 , {12, 34} and {67, 90} Maximum Pages = 157, {12, 34, 67} and {90} Maximum Pages =113. Therefore, the minimum of these cases is 113, which is selected as the output.

Example 2:

Input:

arr = [15,17,20], k = 5

Output:

-1
Explanation: Allocation can not be done.

Example 3:

Input: n = 4, m = 2, arr = [12, 34, 67, 90]

Output: 113

Constraints

1 ≤ n ≤ 1000
1 ≤ m ≤ n
1 ≤ arr[i] ≤ 10000

*/

class Solution
{
public:
    bool isPossibleSolution(int arr[], int n, int m, int Solution)
    {
        int pageSum = 0;
        int c = 1;

        for (int i = 0; i < n; i++)
        {

            if (arr[i] > Solution)
            {
                return false;
            }

            if (pageSum + arr[i] > Solution)
            {
                c++;
                pageSum = arr[i];

                if (c > m)
                {
                    return false;
                }
            }
            else
            {
                pageSum += arr[i];
            }
        }
        return true;
    }

    long long findPages(int n, vector<int> &arr, int m)
    {
        if (m > n)
            return -1;

        int start = 0;
        int end = accumulate(arr.begin(), arr.end(), 0);

        int ans = -1;

        while (start <= end)
        {
            int mid = (start + end) >> 1;

            if (isPossibleSolution(arr.data(), n, m, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }
};