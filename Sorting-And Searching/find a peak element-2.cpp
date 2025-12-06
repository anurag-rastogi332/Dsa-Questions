#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/*

A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

 

Example 1:



Input: mat = [[1,4],
             [3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
Example 2:



Input: mat = [[10,20,15],
             [21,30,14],
             [7,16,32]]
Output: [1,1]
Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
 

*/


class Solution{
public:
    int findMaxIndex(vector<vector<int>> &mat, int n, int m, int j)
    {
        // find jth midth column's colm wise max element
        int maxi = INT_MIN;
        int index = -1;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][j] > maxi)
            {
                maxi = mat[i][j];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int s = 0, e = m - 1; // colm wise
        while (s <= e)
        {
            int mid = (s + e) / 2;
            int maxRowIndex = findMaxIndex(mat, n, m, mid);
            // now my approach deduced to 1D Sort of thinking
            int left = mid - 1 >= 0 ? mat[maxRowIndex][mid - 1] : INT_MIN;
            int right = mid + 1 < m ? mat[maxRowIndex][mid + 1] : INT_MIN;

            if (mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right)
            {
                return {maxRowIndex, mid};
            }
            else if (mat[maxRowIndex][mid] < left)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return {};
    }
};