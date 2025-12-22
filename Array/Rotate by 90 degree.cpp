#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*

Given a square matrix mat[][] of size n x n. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space.

Examples:

Input: mat[][] = [[0, 1, 2],
                [3, 4, 5],
                [6, 7, 8]]
Output: [[2, 5, 8],
        [1, 4, 7],
        [0, 3, 6]]
Input: mat[][] = [[1, 2],
                [3, 4]]
Output: [[2, 4],
        [1, 3]]

*/

// rotate by 90 degree   anticlock wise
class Solution
{
public:
    void rotateMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // Transepose of a matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Matrix ko 90 degree anticlockwise rotate karne ke liye column-wise swap kar rahe hain

        for (int j = 0; j < n; j++)
        {
            int top = 0, bottom = n - 1;
            while (top < bottom)
            {
                swap(matrix[top][j], matrix[bottom][j]);
                top++;
                bottom--;
            }
        }
    }
};
